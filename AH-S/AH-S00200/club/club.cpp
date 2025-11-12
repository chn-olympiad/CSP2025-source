#include<bits/stdc++.h>
using namespace std;
int h[10005][3];
int t;
int s=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int v=0;v<t;v++){
		int n;
		cin>>n;
		int a[n],b[n],c[n];
		for(int i=0;i<n;i++){
			cin>>h[i][1];
			cin>>h[i][2];
			cin>>h[i][3];
			a[i]=i;
			b[i]=i;
			c[i]=i;
		}

		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(h[a[i]][1]>h[a[j]][1])
					swap(a[i],a[j]);
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(h[b[i]][1]>h[b[j]][1])
					swap(b[i],b[j]);
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(h[c[i]][1]>h[c[j]][1])
					swap(c[i],c[j]);
		int m[n],mm[n];
		int id1[10005];
		int id2[10005];
		for(int i=0;i<n;i++)
			for(int j=0;j<3;j++){
				if(h[i][j]>m[i]){
					m[i]=h[i][j];
					id1[i]=j;
				}
				if(h[i][j]<m[i] && h[i][j]>mm[i]){
					mm[i]=h[i][j];
					id2[i]=j;
				}
			}
		int hc[n];
		int g=0;
		for(int i=0;i<n;i++)
			if(a[i]==id1[1]){
				hc[g]=a[i];
				g++;
			}
		int zd=n/2;
		if(g<=zd)
			for(int i=0;i<g;i++)
				s+=hc[n];
		else{
			for(int i=0;i<zd;i++)
				s+=h[i][1];
		}
		
		g=0;
		for(int i=0;i<n;i++)
			if(b[i]==id1[2]){
				hc[g]=b[i];
				g++;
			}
		if(g<=zd)
			for(int i=0;i<g;i++)
				s+=hc[n];
		else{
			for(int i=0;i<zd;i++)
				s+=h[i][1];
		}
		
		g=0;
		for(int i=0;i<n;i++)
			if(c[i]==id1[3]){
				hc[g]=c[i];
				g++;
			}
		if(g<=zd)
			for(int i=0;i<g;i++)
				s+=hc[n];
		else{
			for(int i=0;i<zd;i++)
				s+=h[i][1];
		}
		
		cout<<s<<endl;
	}
	
	
	return 0;
}
