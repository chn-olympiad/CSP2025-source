#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500010;
ll n,k,a[N],cnt,m,l1[N],l2[N],l3[N],x=1;
bool c[N];
int main(){
	ifstream fin("xor.in");
	ofstream fout("xor.out");
	fin>>n>>k;
	for(int i=1;i<=n;i++) fin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j) m=a[i];
			else{
				m=a[i];
				for(int k=i+1;k<=j;k++){				
					m=m|a[k];
				}
			}	
			if(m==k){
				cnt++;
				l1[x]=i;
				l2[x]=j;
				x++;
			}
		}
	}
	for(int i=1;i<x;i++){
		for(int j=i+1;j<x;j++){
			if((l1[i]<=l1[j]&&l2[i]>=l2[j]&&c[i]==0)||(l1[i]>=l1[j]&&l2[i]<=l2[j]&&c[i]==0)||(l1[j]==l2[i]&&c[i]==0)) {
				cnt--;
				c[j]=1;
			}
		}
	}
	fout<<cnt;
} 
