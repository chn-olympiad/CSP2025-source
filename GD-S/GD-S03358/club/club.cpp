#include<bits/stdc++.h>
using namespace std;
struct kkk{
	long long a,b,c,val,id;
	bool operator < (const kkk a) const{
		return val<a.val;
	}
}a[100010];
void slove(){
	int n;
	cin>>n;
	vector<kkk> A,B,C;
	long long ans = 0;
	for(int i = 1;i <= n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
		a[i].id = i;
		long long mx = max(a[i].a,max(a[i].b,a[i].c));
		ans+=mx;
		if(a[i].a == mx){
			a[i].val = min(a[i].a-a[i].b,a[i].a-a[i].c);
			A.push_back(a[i]);
		}
		else if(a[i].b == mx){
			a[i].val = min(a[i].b-a[i].a,a[i].b-a[i].c);
			B.push_back(a[i]);
		}
		else{
			a[i].val = min(a[i].c-a[i].a,a[i].c-a[i].b);
			C.push_back(a[i]);
		}
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	sort(C.begin(),C.end());
	if(A.size()>n/2){
		int t = A.size()-n/2;
		for(int i = 0;i < t;i++){
			ans-=A[i].val;
		}
	}
	if(B.size()>n/2){
		int t = B.size()-n/2;
		for(int i = 0;i < t;i++){
			ans-=B[i].val;
		}
	}
	if(C.size()>n/2){
		int t = C.size()-n/2;
		for(int i = 0;i < t;i++){
			ans-=C[i].val;
		}
	}
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		slove();
	} 
	return 0;
}
