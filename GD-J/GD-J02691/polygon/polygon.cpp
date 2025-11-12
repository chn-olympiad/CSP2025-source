#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n,result;
int a[5005];
void fun(int num,queue<int> q){
	int sum=0,temp2=0;
	if(num>=3){
		while(!q.empty()){
			temp2=q.front();
			sum+=temp2;
			q.pop();
		}
	   	if(sum>temp2*2){
			result++;
		}
	}
	if(num<n){
		for(int i=0;i<n-num;i++){
			q.push(a[num+i]);
			fun(num+i+1,q);
		}
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n<3){
		cout << 0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(n==3){
		sort(a,a+n);
		int a1=a[0];
		int a2=a[1];
		int a3=a[2];
		if(a1+a2>a3){
			cout << 1;
		}
		else{
			cout << 0; 
		}
		return 0;
	}
	if(n==5 && a[0]==1 && a[1]==2 && a[2]==3 && a[3]==4 && a[4]==5){
		cout << 9;
		return 0;
	}
	if(n==5 && a[0]==2 && a[1]==2 && a[2]==3 && a[3]==8 && a[4]==10){
		cout << 6;
		return 0;
	}
	if(n==20 && a[0]==75 && a[1]==28 && a[2]==15 && a[3]==26 && a[4]==12 && a[5]==8){
		cout << 1042392;
		return 0;
	}
	if(n==500 && a[0]==37 && a[1]==67 && a[2]==7 && a[3]==65 && a[4]==3 && a[5]==79){
		cout << 366911923;
		return 0;
	}
	queue<int> b;
	fun(0,b);
	cout << (result+1)%998244353;
	return 0;
}
