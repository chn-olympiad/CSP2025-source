#include<bits/stdc++.h>
using namespace std;
struct stu{
	int a1,a2,a3,c12o1,c12o2,c12o3;
}a[200050];
bool cmp1(stu a,stu b){
	return a.c12o1<b.c12o1;
}
bool cmp2(stu a,stu b){
	return a.c12o2<b.c12o2;
}
bool cmp3(stu a,stu b){
	return a.c12o3<b.c12o3;
}
int main(){
	freeopen("club.in","r",stdin);
	freeopen("club.out","w",stdout);
	short t;
	cin>>t;
	while(t--){
		int n,b1=0,b2=0,b3=0,r1=0,r2=0,r3=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].c12o1=INT_MAX;
			a[i].c12o2=INT_MAX;
			a[i].c12o3=INT_MAX;
			if(a[i].a1==max(a[i].a1,max(a[i].a2,a[i].a3))){
				b1+=a[i].a1;
				r1++;
				a[i].c12o1=a[i].a1-max(a[i].a2,a[i].a3);
			}else if(a[i].a2==max(a[i].a1,max(a[i].a2,a[i].a3))){
				b2+=a[i].a2;
				r2++;
				a[i].c12o2=a[i].a2-max(a[i].a1,a[i].a3);
			}else if(a[i].a3==max(a[i].a1,max(a[i].a2,a[i].a3))){
				b3+=a[i].a3;
				r3++;
				a[i].c12o3=a[i].a3-max(a[i].a2,a[i].a1);
			}
		}ans=b1+b2+b3;
		if(r1<=n/2&&r2<=n/2&&r3<=n/2){
			cout<<ans<<endl;
			continue;
		}else if(r1>n/2){
			sort(a+1,a+n+1,cmp1);
			int cha=r1-n/2;
			for(int i=1;i<=cha;i++){
				ans-=a[i].c12o1;
			}
		}else if(r2>n/2){
			sort(a+1,a+n+1,cmp2);
			int cha=r2-n/2;
			for(int i=1;i<=cha;i++){
				ans-=a[i].c12o2;
			}
		}else if(r3>n/2){
			sort(a+1,a+n+1,cmp3);
			int cha=r3-n/2;
			for(int i=1;i<=cha;i++){
				ans-=a[i].c12o3;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}