#include<bits/stdc++.h>
using namespace std;
int s[1000005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    cin>>s[i];
    int R=s[1];
    sort(s+1,s+n*m+1);
    int wei;
    for(int i=n*m;i>=1;i--){
    	if(s[i]==R){
    	wei=n*m-i+1;
    	break;
		}
    }
    int lie,hang;
    if(wei%n==0){
    lie=wei/n;
    if(lie%2==1)
    hang=n;
    else
    hang=1;
    }
    else{
    lie=wei/n+1;
	if(lie%2==1)
    hang=wei%n;
    else
    hang=n-wei%n+1;
	}
	cout<<lie<<" "<<hang;
	return 0;
}
