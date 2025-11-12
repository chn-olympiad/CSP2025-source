#include<bits/stdc++.h>
using namespace std;
int Alice;
bool cmp(int a,int b){
	return a>b;
}
int arr[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b;
	cin>>a>>b;
	
	int brr[130];
	for(int i=1;i<=a*b;i++){
		cin>>brr[i];	
	}
	Alice=brr[1];
	int anscnt=0;
	sort(brr+1,brr+a*b+1,cmp);
	for(int j=1;j<=b;j++){
		if(j%2==1){
			for(int i=1;i<=a;i++){anscnt++;
				arr[i][j]=brr[anscnt];
			}
		}
		else if(j%2==0){
			for(int i=a;i>=1;i--){anscnt++;
				arr[i][j]=brr[anscnt];
			}
		}
	}
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			if(arr[i][j]==Alice){
				cout<<i<<" "<<j;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
