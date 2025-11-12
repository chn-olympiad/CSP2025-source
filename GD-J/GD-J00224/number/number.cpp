#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int N=1e6+10;
char a[N];
ll A[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=N;i++){
		if(A[i]){
			break;
		}
		cin >> a[i];
		if(a[i]<=9 && a[i]>=0){
			A[i]=a[i];
		}
	}
	sort(A+1,A+N+1);
	for(int i=1;i<=N;i++){
		cout << A[i];
	}
	return 0;
}
