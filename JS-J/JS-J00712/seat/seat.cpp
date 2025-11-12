#include <bits/stdc++.h>
using namespace std;
int a[110],s[20][20];
bool cmp(int x,int y){
    return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int p=n*m;
	int k;
	cin>>k;
	a[1]=k;
	for(int i=2;i<=p;i++){
        cin>>a[i];
	}
	sort(a+1,a+p+1,cmp);
	for(int i=1;i<=p;i++){
        if(a[i]==k){
            k=i;
        }
	}
	if(k<n){
        cout<<k%n<<" "<<k;
	}
	else if(k==n){
        cout<<1<<" "<<n;
	}
	else{
        cout<<k/n+1<<" ";
        if((k/n+1)%2==0){
            if(k/n-1==0){
                cout<<n;
            }
            else cout<<k/n-1;
        }
        else{
            cout<<n-(k%n+1);
        }
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
