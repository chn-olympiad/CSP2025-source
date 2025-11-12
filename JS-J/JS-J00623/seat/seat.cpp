#include<bits/stdc++.h>
using namespace std;
int a[105];
int p;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s;
	for(int i=0;i<n*m;i++){
		int t;
		cin>>t;
		if(i==0){
			s=t;
		}else{
			a[p]=t;p++;
		}
	}
	sort(a,a+p);
	int q=1;
	for(int i=p-1;i>=0;i--){
		if(s>a[i])break;
		else{
			q++;
		}
	}
	if(q%n==0){
		cout<<q/n<<" ";
		if((q/n)%2==0)cout<<1;
		else{
			cout<<n;
		}
	}
	else{
		cout<<q/n+1<<" ";
		if((q/n)%2==0)cout<<q%n;
		else{
			cout<<n+1-(q%n);
		}
	}
	
	return 0;
}
