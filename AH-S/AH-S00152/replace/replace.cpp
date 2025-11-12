#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q,f[N];
string s[N][4],t1,t2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
		cin>>t1>>t2;
		if(t1==t2){f[i]=1;continue;}
		int x=t1.size(),l,r;
	    for(l=0;l<x;l++)
	        if(t1[l]==t2[l]) s[i][0]=s[i][0]+t1[l];
	        else break;
	    for(r=x-1;r>=0;r--)
	        if(t1[r]==t2[r]) s[i][1]=s[i][1]+t1[r];
	        else break;
	    for(int j=l;j<=r;j++) 
	        s[i][2]=s[i][2]+t1[j],s[i][3]=s[i][3]+t2[j];
	}
	while(q--){
	    cin>>t1>>t2;
	    int ans=0,x=t1.size(),x2=t2.size(),l,r;
	    if(x!=x2){printf("0\n");continue;}
	    string t3="",t4="",t5="",t6="";
	    for(l=0;l<x;l++)
	        if(t1[l]==t2[l]) t3=t3+t1[l];
	        else break;
	    for(r=x-1;r>=0;r--)
	        if(t1[r]==t2[r]) t4=t4+t1[r];
	        else break;
	    for(int j=l;j<=r;j++) 
	        t5=t5+t1[j],t6=t6+t2[j];
	    for(int i=1;i<=n;i++){
		    if(f[i]) continue;
		    int y1=t3.size(),y2=t4.size(),y3=s[i][0].size(),y4=s[i][1].size();
		    if(s[i][2]==t5&&s[i][3]==t6&&y3<=y1&&y4<=y2&&t3.substr(y1-y3,y3)==s[i][0]&&t4.substr(y2-y4,y4)==s[i][1]) ans++;
		}
		printf("%d\n",ans);
	}
    return 0;
}
