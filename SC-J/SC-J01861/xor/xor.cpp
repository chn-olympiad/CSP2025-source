#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,k,a[N],s[N],qp[25],ans;
vector<int>r;
set<int>se;
vector<int> change(int x){
	vector<int>wb; 
	if(x==0){
		wb.push_back(0);
		return wb;
	}
	int w=log2(x)+1;
	bool ispu=0;
	while(w>=0){
		if(x-qp[w]>=0){
			x-=qp[w];
			ispu=1;
			wb.push_back(1);
		}
		else{
			if(ispu)wb.push_back(0);
		}
		w--;
	}
	reverse(wb.begin(),wb.end());
	return wb;
}
int calc(int p){
	int jb=0;
	vector<int>pla;
	vector<int>fr=change(p);
	int msz=min((int)fr.size(),(int)r.size()),mxz=max((int)fr.size(),(int)r.size());
	for(int i=0;i<msz;i++){
		if(r[i]==0){
			if(fr[i]==0){
				pla.push_back(0);
			}
			else{
				pla.push_back(1);
			}
		}
		else{
			if(fr[i]==0){
				pla.push_back(1);
			}
			else{
				pla.push_back(0);
			}
		}
	}
	for(int i=msz;i<mxz;i++){
		if(i>=r.size()){
			pla.push_back(fr[i]);
		}
		else{
			pla.push_back(r[i]);
		}
	}
	while(pla.size()&&pla.back()==0){
		pla.pop_back();
	}
	if(pla.size()==0){
		pla.push_back(0);
	}
	for(int i=0;i<pla.size();i++){
		jb+=pla[i]*qp[i];
	}
	return jb;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	qp[0]=1;
	for(int i=1;i<=22;i++){
		qp[i]=qp[i-1]*2;
	}
	cin>>n>>k;
	r=change(k);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		se.insert(s[i-1]);
		int need_val=calc(s[i]);
		if(se.find(need_val)!=se.end()){
			ans++;
			se.clear();
		}
	}
	cout<<ans;
}