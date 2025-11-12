#include<iostream>
#include<queue>
using namespace std;
int n,k,t,l;
long long cnt;
long long a[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=0;i<=n-1;i++){
		cin>>a[i];
	}
	l = 0;
	cnt = 0;
	for (int g=0;g<=n-1;g++){
		t = a[g];
		for (int h=g+1;h<=n-1;h++){
			if (t==k){
				cnt++;
				g += l;
				l = 0;
				break;
			}else{
				t = t^a[h];
				l++;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
