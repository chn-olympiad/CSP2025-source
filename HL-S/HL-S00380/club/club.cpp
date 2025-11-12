#include<bits/stdc++.h>
using namespace std;
int t,n,ans[100100],cnt,d[100010],e[100010],o,p,q;
cmp(int x,int y){
	return x>y;
}
struct node{
	int a;
	int b;
	int c;
}box[100100];
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
		   cin>>box[j].a>>box[j].b>>box[j].c;
		   o+=box[j].a;
		   p+=box[j].b;
		   q+=box[j].c;	
		}
        for(int j=1;j<=n;j++){
            d[j]=max(box[j].a,box[j].b);
            e[j]=max(box[j].c,d[j]);
		}
		sort(e+1,e+1+n,cmp);
		for(int j=1;j<=n;j++){
        cnt+=e[j];	
		}
        ans[i]=cnt;
	    cnt=0;
	}
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}