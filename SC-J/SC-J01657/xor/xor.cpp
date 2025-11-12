#include<bits/stdc++.h>
using namespace std;

const int N=1e5*5+100;
long long n,k;
int bjk;
long long a[N];
int rjz[500000];
int zhrjz[500000];
int bjrjz[500000];
int H=0;
bool bja[N];

int zrjz(long long a){
	int k=0;
	while (a!=0){
		k++;
		rjz[k]=a%2;
//		if (bjrjz[k]==0 && rjz[k]==1){
//			bjrjz[k]++;
//		}
		a=int(a/2);
		if (a==0){
			break;
		}
	}
	return k;
}

//int zsjz(int b[500000],int k){
//	int u=0;
//	for (int i=1;i<=k;i++){
//		u+=pow(2,i-1);
//	}
//	return u;
//}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k ;
	for (long long i=1;i<=n;i++){
		cin >> a[i] ;
	}
	if (k>0 && k<1){
		cout << 0 ;
		return 0;
	}
	if(k==1){
		for (int i=1;i<=n;i++){
			if (a[i]==1){
				H++;
			}
		}
		cout << H ;
		return 0;
	}
	if (k==0){
		for (int i=1;i<=n;i++){
			if (a[i]==0){
				H++;
			}
		}
		cout << H ;
		return 0;
	}
	bjk=zrjz(k);
	int f=bjk;
	for (int i=1;i<=bjk;i++){
		bjrjz[i]=rjz[i];
	}
	int maxk=0;
	int v=0;
	for (long long i=1;i<=n;i++){
		for (long long j=i;j<=n;j++){
			bjk=zrjz(a[i]);
			maxk=max(maxk,bjk);
			for (int h=1;h<=bjk;h++){
				if (rjz[i]==1 && zhrjz[i]==0){
					zhrjz[i]++;
				}
			}
			if (maxk==f){
				
				for (int p=1;p<=f;p++){
					if (zhrjz[p]==bjrjz[p]){
						v=1;
					}else{
						break;
					}
				}
			}else{
				break;
			}
			if (v==1){
				for (int e=i;e<=j;e++){
					if (bja[i]!=1){
						bja[i]=1;
					}else{
						int v=0;
						break;
					}
				}
				if (v!=0){
					H++;
				}
			}
		}
	}
	cout << H ;
	
	return 0;
}