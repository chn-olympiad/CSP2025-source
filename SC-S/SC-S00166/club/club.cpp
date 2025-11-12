#include<bits/stdc++.h>//A-club
using namespace std; 
long long t,n,ans,n1,n2,n3;
struct cc{
	long long q1,q2,q3,mn;
}a[100005];
bool hel1(cc l,cc r){
	if(l.mn!=r.mn) return l.mn<r.mn;
	return min(l.q1-l.q2,l.q1-l.q3)<min(r.q1-r.q2,r.q1-r.q3);
}
bool hel2(cc l,cc r){
	if(l.mn!=r.mn){
		return abs(l.mn-2)<abs(r.mn-2);
	}
	return min(l.q2-l.q1,l.q2-l.q3)<min(r.q2-r.q1,r.q2-r.q3);
}
bool hel3(cc l,cc r){
	if(l.mn!=r.mn) return l.mn>r.mn;
	return min(l.q3-l.q2,l.q3-l.q1)<min(r.q3-r.q2,r.q3-r.q1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		ans=n1=n2=n3=0;
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>a[i].q1>>a[i].q2>>a[i].q3;
			long long f=a[i].q1;
			a[i].mn=1;
			if(a[i].q2>f) f=a[i].q2,a[i].mn=2;
			if(a[i].q3>f) f=a[i].q3,a[i].mn=3;
			ans+=f;
			if(a[i].mn==1) n1++;
			if(a[i].mn==2) n2++;
			if(a[i].mn==3) n3++;
			
		}
		if(n1>n/2){
			long long q=n1-n/2;
			sort(a+1,a+n+1,hel1);
			for(long long i=1;i<=q;i++){
				ans-=min(a[i].q1-a[i].q2,a[i].q1-a[i].q3);
			}
		}
		else if(n2>n/2){
			long long q=n2-n/2;
			sort(a+1,a+n+1,hel2);
			for(long long i=1;i<=q;i++){
				ans-=min(a[i].q2-a[i].q1,a[i].q2-a[i].q3);
			}
		}
		else if(n3>n/2){
			long long q=n3-n/2;
			sort(a+1,a+n+1,hel3);
			for(long long i=1;i<=q;i++){
				ans-=min(a[i].q3-a[i].q2,a[i].q3-a[i].q1);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}