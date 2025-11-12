#include <bits/stdc++.h>
using namespace std;
int n,k;
int ans;
int a[500005];
int t[25];
bool check_A(){
	for(int i=1;i<=n;++i){
		if(a[i]!=1){
			return false;
		}
	}
	return true;
}
bool check_B(){
	for(int i=1;i<=n;++i){
		if(a[i]!=1 && a[i]!=0){
			return false;
		}
	}
	return true;
}
int Count(int x){
	int cnt=0;
	while(x){
		cnt++;
		x>>=1;
	}
	return cnt;
}
void add(int x){
	int n=Count(x);
	for(int i=0;i<n;++i){
		if((x>>i)&1){
			t[i]++;
		}
	}
}
void getout(int x){
	int n=Count(x);
	for(int i=0;i<n;++i){
		if((x>>i)&1){
			t[i]--;
		}
	}
}
bool check_end(){
	if(k==0){
		for(int i=0;i<=21;++i){
			if(t[i]%2==1){
				return false;
			}
		}
		return true;
	}
	for(int i=0;i<Count(k);++i){
		if(t[i]%2==0){
			return false;
		}
	}
	for(int i=Count(k);i<=21;++i){
		if(t[i]%2==1){
			return false;
		}
	}
	return true;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(check_A()){
		if(n==1){ cout<<0;return 0; }
		else if(n%2==1){ cout<<2;return 0; }
		else{ cout<<1;return 0; }
	}
	if(check_B()){
		if(k==0){
			int cnt=0;
			for(int i=1;i<=n;++i)
				if(a[i]==0){
					ans+=cnt/2;
					ans++;
					cnt=0;
				}else cnt++;
			if(cnt) ans+=cnt/2;
		}else if(k==1){
			int cnt=0;
			for(int i=1;i<=n;++i) if(a[i]==1) ans++;
		}
		cout<<ans;
		return 0;
	}
	int Ck=Count(k);
	int l=1;
	for(int i=1;i<=n;++i){
		add(a[i]);
		bool flag=0;
		if(check_end()){
			ans++;
			l=i+1;
			for(int i=0;i<Ck;++i) t[i]=0;
			continue;
		}
		for(int j=l;j<i;++j){
			int tmp=a[j];
			getout(tmp);
			if(check_end()){
				ans++;
				l=i+1;
				for(int i=0;i<Ck;++i) t[i]=0;
				flag=1;
				break;
			}
		}
		if(!flag)
			for(int j=l;j<i;++j){
				add(a[j]);
			}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
