#include<bits/stdc++.h>

using namespace std;

#define endl "\n"

using ll=long long;

bool cmp(int a,int b){
	return a>b;
}
int pn[20][20];

void solve(){
	int n,m;
	cin>>n>>m;
	int nm=n*m;
	vector<int> s(nm+8);
	for(int i=1;i<=nm;i++){
		cin>>s[i];
	}
	int pp=s[1],u;
	sort(s.begin()+1,s.begin()+nm+1,cmp);
	for(int i=1;i<=nm;i++){
		if(s[i]==pp){
			u=i;
			break;
		}
	}
	int nn,mm;
	mm=(u+n-1)/n;
	if(mm%2==0){
		nn=n-(u-(mm-1)*n)+1;
	}else{
		nn=u-(mm-1)*n;
	}
	cout<<mm<<' '<<nn;
	return;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	solve();
	return 0;
} 
