#include<bits/stdc++.h>
using namespace std;
int n=1,m=1,a[101],b[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int p,pm;
	p=a[1];
	sort(a,a+(n*m)+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			pm=i;
			break;
		}
	}
	pm=n*m+1-pm;
	int n_=1,m_=1;
	int cnt=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cnt++;
			if(cnt==pm){
				cout<<m_<<" "<<n_; 
				return 0;
			}
			n_++;
		}
		i++;m_++;
		for(int j=n;j>=1;j--){
		    cnt++;
			if(cnt==pm){
				cout<<m_<<" "<<n_; 
				return 0;
			}
			n_--;
		}
		m_++;
	}
	return 0;
}
