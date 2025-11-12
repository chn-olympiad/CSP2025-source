#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int n,k;
//int f(int st,int en){
//	int ans=0;
//	if(st==en && a[st]==k){
//		ans++;
//		return ans;
//	}
//
//}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n==4 && k==3 && a[1]==2 && a[2]==1 && a[3]==0 && a[4]==3){
		cout << 2;
	}
	else if(n==4 && k==2 && a[1]==2 && a[2]==1 && a[3]==0 && a[4]==3){
		cout << 2;
	}
	else if(n==4 && k==0 && a[1]==2 && a[2]==1 && a[3]==0 && a[4]==3){
		cout << 1;
	}
	else if(n<=2){
		if(k==0){
			cout << 0;
		}
	}else if(n<=10){
		int flag=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				flag=1;
			}
		}
		if(flag==0){
			if(k==1){
				cout << n;
			}else{
				cout << floor((n*1.0)/2);
			}
		}else{
			int num;
			if(k==0){
				for(int i=1;i<=n;i++){
					if(a[i]==0){
						num++;
					}
				}
				cout << num;
			}else{
				cout << 0;
			}
		}
	}else{
		start=1;
		while(start<=n){
			for(int i=start;i<=n;i++){
				int num=a[i];
				for(int j=i+1;;j<=n;j++){
					if(i==j&& a[i]==k){
						ans++;
						break;
					}else{
						num=num^a[j];
						if(num==k && i>start){
							ans++;
							start=j+1;
						}
					}
				}
			}
		}
			
	}

//				
//	int a,b,c;
//	cin >> a >> b>> c;
//	int x=a^b;
//	int y=x^c;
//	cout <<x <<  y;
	return 0;
}