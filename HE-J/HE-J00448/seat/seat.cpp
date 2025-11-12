
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int count=n*m;
	int a[count+1];
	for(int i=1;i<=count;i++){
		cin>>a[i];
	}
	int b;
	b=a[1];
	for(int i=1;i<=count;i++){
		for(int j=1;j<=count-1;j++){
			if(a[j]<a[j+1]){
				int c=a[j];
				a[j]=a[j+1];
				a[j+1]=c;
			}
		}
	}
	int c=0;
	for(int i=1;i<=count;i++){
		if(a[i]==b){
			c=i;
			break;
		}
	}
	int yushu=c%n;
	int shang=c/n;
	if(yushu==0){	
		if(shang%2==1){
			cout<<shang<<" "<<n;
		}
		else{
			cout<<shang<<" "<<1;
		}
	}
	else{
		if((shang+1)%2==1){
			cout<<shang+1<<" "<<yushu;
		}
		else{
			cout<<shang+1<<" "<<n-yushu+1;
		}
	}
	return 0;
}
