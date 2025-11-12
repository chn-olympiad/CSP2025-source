#include<bits/stdc++.h>
using namespace std;

int hhh[10],s=0;

int abc(int z[],int n){
	int a=0,b=0,c=0;
	for (int i=0 ; i<n ; i++){
		if (z[i]==0)a++;
		if (z[i]==1)b++;
		if (z[i]==2)c++;
	}
	if (a<=n/2 && b<=n/2 && c<=n/2) return 1;
	return 0;
}

int qwe(int z[],int z_q[],int mid[],int mid_q[],int min[],int min_q[],int n){
	int o=0,max[n],max_q[n];
	for (int i=0 ; i<n ; i++){
		max[i]=z[i];
		max_q[i]=z_q[i];
	}
			
	for (int i=0 ; i<n ; i++){
		for (int g=0 ; g<n ; g++){
			max[g]=z[g];
			max_q[g]=z_q[g];
		}
		max_q[i]=mid_q[i];
		if (abc(max_q,n)){
			max[i]=mid[i];
			int f=0;
			for (int j=0 ; j<n ; j++){
				f+=max[j];
			}
			if (f>o)o=f;
		}
	}
	for (int i=0 ; i<n ; i++){
		for (int g=0 ; g<n ; g++){
			max[g]=z[g];
			max_q[g]=z_q[g];
		}
		max_q[i]=mid_q[i];
		max_q[i+1]=mid_q[i+1];
		if (abc(max_q,n)){
			max[i]=mid[i];
			max[i+1]=mid[i+1];
			int f=0;
			for (int j=0 ; j<n ; j++){
				f+=max[j];
			}
			if (f>o)o=f;
		}
	}
	cout<<o<<endl;
	return 0;
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	cin>>t;
	for (int v=0 ; v<t ; v++){
		int n=0;
		cin>>n;
		int a[n],b[n],c[n],max[n],max_q[n],mid[n],mid_q[n],min[n],min_q[n];
		for (int i=0 ; i<n ; i++) cin>>a[i]>>b[i]>>c[i];
		
		for (int i=0 ; i<n ; i++){
			max[i]=a[i];
			max_q[i]=0;
			mid[i]=b[i];
			mid_q[i]=1;
			min[i]=c[i];
			min_q[i]=2;
			if (a[i]<b[i]){
				max[i]=b[i];
				max_q[i]=1;
				mid[i]=a[i];
				mid_q[i]=0;
				min[i]=c[i];
				min_q[i]=2;
				if (b[i]<c[i]){
					max[i]=c[i];
					max_q[i]=2;
					mid[i]=b[i];
					mid_q[i]=1;
					min[i]=a[i];
					min_q[i]=0;
				}
			}
			else if (a[i]<c[i]){
				max[i]=c[i];
				max_q[i]=2;
				mid[i]=a[i];
				mid_q[i]=0;
				min[i]=b[i];
				min_q[i]=1;
				
			}
			else if (b[i]<c[i]){
				max[i]=a[i];
				max_q[i]=0;
				mid[i]=c[i];
				mid_q[i]=2;
				min[i]=b[i];
				min_q[i]=1;	
			}
		}
		
		if (abc(max_q,n)){
			int asd=0;
			for (int i=0 ; i<n ; i++){
				asd+=max[i];
			}
			cout<<asd<<endl;
		}else{
			qwe(max,max_q,mid,mid_q,min,min_q,n);
			
		}
		
		
	}
	return 0;
}
