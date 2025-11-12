#include<bits/stdc++.h>

using namespace std;

const int N=2e5+10,inf=1e9;
string s[N],t[N];
string a,b;
int n,m;
int L,R;

void get(){
	int n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]){
			L=min(L,i);
			R=max(R,i);
		}
	}
}

bool check(int x){
	int n=a.size(),m=s[x].size();
	for(int i=max(m-1,R);i<n;i++){
		if(i-m+1>L){
			continue;
		}
		bool die=1;
		int cnt=m;
		for(int j=i;j>=i-m+1;j--){
			cnt--;
			if(a[j]!=s[x][cnt] || b[j]!=t[x][cnt]){
				die=0;
				break;
			}
		}
		if(die){
			return true;
		}
	}
	return false;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
	}
	
	while(m--){
		L=inf,R=0;
		cin>>a>>b;
		get();
		int ret=0;
		for(int i=1;i<=n;i++){
			if(check(i)){
				ret++;
			}
		}
		printf("%d\n",ret); 
	}
	
	return 0;
}
