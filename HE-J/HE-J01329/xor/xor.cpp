#include<iostream>
#include<cstdio>
using namespace std;
int arr[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int N,k;
	cin >> N >> k;
	for(int i=0;i<N;i++){
		cin >> arr[i];
	}
	int temp,cnt=0;
	for(int i=0;i<N;i++){
		temp=arr[i];
		while(temp!=k&&i<N){
			i++;
			temp=temp xor arr[i];
		}
		cnt++;
	}
	cout << cnt;
	return 0;
}
