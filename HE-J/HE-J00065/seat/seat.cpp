#include <bits/stdc++.h>
using namespace std;
int a[10010],num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	num=a[1];
	int j=n*m;
	int y=1,k;
	sort(a+1,a+j+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==num)
		{
		k=y;
		break;
		}
		y++;
	}
	if(k==1) {
		cout<<1<<" "<<1; 
	}
	else{
		if(k%n==0){
			if((k/n)%2!=0){
				cout<<k/n<<" "<<n;
			}
			else{
				cout<<k/n+1<<" "<<k%n;
			}
		}
		else{
			if((k/n+1)%2==0)
			{
				cout<<k/n+1<<" "<<m-(k%n)+1;
			}
			else{
				cout<<k/n+1<<" "<<k%n;
			}
			
		}
	}
	fclose(stdin);
	fclose(stdout);

	return 0;
}
