#include<bits/stdc++.h>
using namespace std;
unsigned long long pr[5001000];
struct kkk{
	string a;
	int len;
	vector<unsigned long long> hsh;
	void init(){
		len = a.size();
		a = " "+a;
		int sz = a.size();
		hsh.push_back(0);
		for(int i = 1;i < sz;i++){
			hsh.push_back(hsh[i-1]*113+a[i]);
		}
		return;
	}
	unsigned long long gethash(int l,int r){
		if(l>r)return 0;
		return hsh[r]-(hsh[l-1]*pr[r-l+1]);
	}
};
void init(){
	pr[0] = 1;
	for(int i = 1;i <= 5000001;i++){
		pr[i] = pr[i-1]*113;
	}
}
int n,q;
vector<pair<kkk,kkk>> vec;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	init();
	cin>>n>>q;
	for(int i = 1;i <= n;i++){
		kkk a,b;
		cin>>a.a>>b.a;
		a.init();
		b.init();
		vec.push_back({a,b});
	}
	while(q--){
		int cnt = 0;
		kkk a,b;
		cin>>a.a>>b.a;
		a.init();
		b.init();
		for(pair<kkk,kkk> v:vec){
			kkk st = v.first,ed = v.second;
			for(int l = 1,r = l+st.len-1;r<=a.len;r++,l++){
				if(a.gethash(l,r) == st.gethash(1,st.len)){
				//	cout<<st.a<<endl;
				//	cout<<a.gethash(1,l-1)+pr[l-1]*ed.gethash(1,ed.len)+pr[r]*a.gethash(r+1,a.len)<<" "<<b.gethash(1,b.len)<<endl;
					if(a.gethash(1,l-1) == b.gethash(1,l-1)&&ed.gethash(1,ed.len) == b.gethash(l,r)&&a.gethash(r+1,a.len) == b.gethash(r+1,b.len)){
						cnt++;
						
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
