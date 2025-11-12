#include<bits/stdc++.h>
using namespace std;
int t;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		bool f[100004]={0};
		int n;
		int a1=0,a2=0,a3=0;
		int as=0;
		cin>>n;
		if(n==2){
			int s1,s2,s3,s4,s5,s6;
			cin>>s1>>s2>>s3>>s4>>s5>>s6;
			int maxx1=max(s1,max(s2,max(s3,max(s4,max(s5,s6)))));
			if(maxx1==s1||maxx1==s3||maxx1==s2){
				cout<<maxx1+max(s4,max(s5,s6));
			}else cout<<maxx1+max(s1,max(s2,s3));
			
		}

}
return 0;
}
