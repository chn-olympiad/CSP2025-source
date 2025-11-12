#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
struct stu{
	int s1,s2,s3;
};
bool cmp1(stu x,stu y){
	return x.s1-max(x.s2,x.s3)>=y.s1-max(y.s2,y.s3);
}
bool cmp2(stu x,stu y){
	return x.s2-max(x.s1,x.s3)>=y.s2-max(y.s1,y.s3);
}
bool cmp3(stu x,stu y){
	return x.s3-max(x.s1,x.s2)>=y.s3-max(y.s2,y.s1);
}
stu s[200005];
stu c1[200005],c2[200005],c3[200005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int sum1=0,sum2=0,sum3=0;
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			cin>>s[i].s1>>s[i].s2>>s[i].s3;
			if(s[i].s1>s[i].s2 && s[i].s1>s[i].s3){
				cnt1++;
				c1[cnt1].s1=s[i].s1;c1[cnt1].s2=s[i].s2;c1[cnt1].s3=s[i].s3;
				sum1+=s[i].s1;
			}else if(s[i].s2>s[i].s1 && s[i].s2>s[i].s3){
				cnt2++;
				c2[cnt2].s1=s[i].s1;c2[cnt2].s2=s[i].s2;c2[cnt2].s3=s[i].s3;
				sum2+=s[i].s2;
			}else{
				cnt3++;
				c3[cnt3].s1=s[i].s1;c3[cnt3].s2=s[i].s2;c3[cnt3].s3=s[i].s3;
				sum3+=s[i].s3;
			}
		} 
		int ans=sum1+sum2+sum3;
		if(cnt1<=n/2 && cnt2<=n/2 && cnt3<=n/2){
			ans=sum1+sum2+sum3;
		}else if(cnt1>n/2){
			sort(c1+1,c1+1+cnt1,cmp1);
			while(cnt1>n/2){
				ans-=c1[cnt1].s1-max(c1[cnt1].s2,c1[cnt1].s3);
				cnt1--;
			}
		}else if(cnt2>n/2){
			sort(c2+1,c2+1+cnt2,cmp2);
			while(cnt2>n/2){
				ans-=c2[cnt2].s2-max(c2[cnt2].s1,c2[cnt2].s3);
				cnt2--;
			}
		}else{
			sort(c3+1,c3+1+cnt3,cmp3);
			while(cnt3>n/2){
				ans-=c3[cnt3].s3-max(c3[cnt3].s1,c3[cnt3].s2);
				cnt3--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
