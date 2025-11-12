# include <bits/stdc++.h>
using namespace std;
int l[225];
void f(int n){
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=n-1;j++){
			if(l[j]<l[j+1]){
					int temp=l[j];
					l[j]=l[j+1];
					l[j+1]=temp;
			}
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>l[i];
	}
	int R=l[1],temp1,temp2;
	f(n*m);
	for(int i=1;i<=n*m;i++){
		if(l[i]==R){
			temp1=i/n,temp2=i%n;
			if(temp2==0){
				if(temp1%2==1) temp2=n;
				else temp2=1; 
			}else{
				temp1++;
				if(temp1%2==0) temp2=n-temp2+1;
			}
			cout<<temp1<<" "<<temp2<<endl;
			break;
		}
	}
	return 0;
}

