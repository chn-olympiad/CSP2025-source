#include<bits/stdc++.h>
using namespace std;
int an1[20005],an2[20005],an3[20005];
int A[100005],B[100005],C[100005];
void tese() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>an1[i]>>an2[i]>>an3[i]; 
	}
	long long zf=0;
	long long maxn=0;
	for(int i=1;i<=n/2;i++) {
		maxn = (an1[i],(max(an2[i],an3[i])));
		A[an1[maxn]]++;
		B[an2[maxn]]++;		
		C[an3[maxn]]++;
		int lgx=A[i]+B[i]+C[i];
		if(A[i] <= n/2 || B[i] <= n/2 || C[i] <= n/2 && lgx==n) {
			zf+=maxn;
		} 
		else {
			 maxn -= 1;
			 zf += maxn;
		}
		cout << zf;
	}
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
	   tese();	
	}	
	return 0; 
}

