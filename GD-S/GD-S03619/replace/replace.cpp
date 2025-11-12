#include<bits/stdc++.h>
using namespace std;
int n,q,m,i,j,k,w,t=0,sum=1,ans[20011];
char t1[20011][50011],t2[20011][50011];
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++){
		cin>>t1[i]>>t2[i];
	}
	for(i=1;i<=q;i++){
		cin>>s1>>s2;
		m=s1.length();
		for(j=0;j<m;j++){
			if(s1[j]!=s2[j]){
				for(k=1,w=0;k<=n;k++){
					while(t1[k][w]==s1[j] && t2[k][w]==s2[j]){
						w++;j++;
					}
					if(s1[j]==s2[j]) ans[++t]=10*(j-w)+w;
					j-=w;
				}
			}
		}
	}
	sort(ans+1,ans+t+1);
	for(int i=1,a;i<=t;i++){
		a=1;
		for(int j=1;j<=t;j++){
			if((ans[i]/10<=ans[j]/10 && ans[j]/10<=ans[i]%10) ||
			   (ans[i]/10<=ans[j]%10 && ans[j]%10<=ans[i]%10) ||
			   (ans[j]/10<=ans[i]/10 && ans[i]%10<=ans[j]%10)){
			   	a++;
			   }
			else break;
		}
		sum*=a;
	}
	if(ans[1]==0) cout<<0<<endl;
	else cout<<sum;
	return 0;
}
