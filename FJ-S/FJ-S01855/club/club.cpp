#include<bits/stdc++.h>
using namespace std;
int t;
struct aaa{
	int a,b,c;
}q1[100005],q2[100005],q3[100005],l;
bool a1(aaa k1,aaa k2){
	if(k1.a<k2.a) return k1.a<k2.a;
	else return k1.a>k2.a;
}
bool a2(aaa k1,aaa k2){
	if(k1.b<k2.b) return k1.b<k2.b;
	else return k1.b>k2.b;
}
bool a3(aaa k1,aaa k2){
	if(k1.c<k2.c) return k1.c<k2.c;
	else return k1.c>k2.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int n,a,b,c,cnt1,cnt2,cnt3;
	long long sum;
	for(int i=1;i<=t;i++){
		cin>>n;
		sum=0;
		cnt1=0;cnt2=0;cnt3=0;
		for(int j=1;j<=n;j++){
			cin>>l.a>>l.b>>l.c;
			if(max(l.a,max(l.b,l.c))==l.a){
				q1[++cnt1]=l;
			} else if(max(l.a,max(l.b,l.c))==l.b){
				q2[++cnt2]=l;
			} else if(max(l.a,max(l.b,l.c))==l.c){
				q3[++cnt3]=l;
			}
		}
		sort(q1+1,q1+cnt1+1,a1);
		sort(q2+1,q2+cnt2+1,a2);
		sort(q3+1,q3+cnt3+1,a3);
	while(cnt1>n/2 || cnt2>n/2 || cnt3>n/2){
		if(cnt1>n/2){
			if(q1[cnt1].b>q1[cnt1].c){
				q2[++cnt2]=q1[cnt1];
				cnt1--;
			} else{
				q3[++cnt3]=q1[cnt1];
				cnt1--;
			}
		}
		if(cnt2>n/2){
			if(q2[cnt2].a>q2[cnt2].c){
				q1[++cnt1]=q2[cnt2];
				cnt2--;
			} else{
				q3[++cnt3]=q2[cnt2];
				cnt2--;
			}
		}
		if(cnt3>n/2){
			if(q3[cnt3].a>q3[cnt3].b){
				q1[++cnt1]=q3[cnt3];
				cnt3--;
			} else{
				q2[++cnt2]=q3[cnt3];
				cnt3--;
			}
		}
	}
	for(int j=1;j<=cnt1;j++) sum+=q1[j].a;
	for(int j=1;j<=cnt2;j++) sum+=q2[j].b;
	for(int j=1;j<=cnt3;j++) sum+=q3[j].c;
	cout<<sum<<endl;
	}
	return 0;
}
