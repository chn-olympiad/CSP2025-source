#include<bits/stdc++.h>
using namespace std;
int t,n;
struct student{
	int s1,s2,s3,maxi;
}s[1000000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].s1>>s[i].s2>>s[i].s3;
			s[i].maxi=max(s[i].s1,max(s[i].s2,s[i].s3));
		}
		int cnt1=0,cnt2=0,cnt3=0;
		int ans1=0,ans2=0,ans3=0;
		for(int i=1;i<=n;i++){
			if(s[i].maxi==s[i].s1&&cnt1<n/2){
				cnt1++;
				ans1+=s[i].s1;
			}
			if(s[i].s2==s[i].maxi&&cnt2<n/2){
				cnt2++;
				ans2+=s[i].s2;
			}
			if(s[i].s3==s[i].maxi&&cnt3<n/2){
				cnt3++;
				ans3+=s[i].s3;
			}
		}cout<<ans1+ans2+ans3<<endl;
	}
	return 0;
}
//Ending Time Octet time goes by chaos
