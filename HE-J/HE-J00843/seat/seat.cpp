#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
int g;
int temp;
ll man;
ll n_count;

int main(){

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    int total=n*m;
    cin>>g;
    while(total-1>0){
        cin>>temp;
        if(g<temp){
            man++;
        }
        total--;
    }
    man++;
    if(man%n==0){
    	n_count=man/n;
    	cout<<n_count<<" "<<n;
    	return 0;
	}else{
		n_count=man/n+1;
	}
    ll m_count=man%n;
    if(n_count%2==0){
        m_count=n-m_count+1;
    }
    cout<<n_count<<" "<<m_count;

    return 0;
}
