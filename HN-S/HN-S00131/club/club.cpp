#include<bits/stdc++.h> 
using namespace std;
int t;
int n;
long a[100000],b[100000],c[100000];
int myz=0,ar=0,br=0,cr=0;
int answer(){
	while(ar+br+cr!=n){
	int max[4]={0},k[4]={0};
	if(ar<n/2 && br<n/2 && cr<n/2){
	for(int i=1;i<=n;i++){
		if(a[i]>max[1]){
			max[1]=a[i];
			k[1]=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]>max[2]){
			max[2]=b[i];
			k[2]=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(c[i]>max[3]){
			max[3]=c[i];
			k[3]=i;
		}
	}
	if(max[1]>max[2]&&max[1]>max[3]){
		myz+=max[1];
		ar+=1;
		a[k[1]]=0;
		b[k[1]]=0;
		c[k[1]]=0;
	}
	else if(max[2]>max[1]&&max[2]>max[3]){
		myz+=max[2];
		br+=1;
		a[k[2]]=0;
		b[k[2]]=0;
		c[k[2]]=0;
	}
	else if(max[3]>max[1]&&max[3]>max[2]){
		myz+=max[3];
		cr+=1;
		a[k[3]]=0;
		b[k[3]]=0;
		c[k[3]]=0;
	}
}
else if(ar==n/2 && br<n/2 && cr<n/2){
	for(int i=1;i<=n;i++){
		if(b[i]>max[2]){
			max[2]=b[i];
			k[2]=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(c[i]>max[3]){
			max[3]=c[i];
			k[3]=i;
		}
	}
	if(max[2]>max[3]){
		myz+=max[2];
		br+=1;
		a[k[2]]=0;
		b[k[2]]=0;
		c[k[2]]=0;
	}
	else if(max[3]>max[2]){
		myz+=max[3];
		cr+=1;
		a[k[3]]=0;
		b[k[3]]=0;
		c[k[3]]=0;
	}
}
else if(br==n/2 && ar<n/2 && cr<n/2){
	for(int i=1;i<=n;i++){
		if(a[i]>max[1]){
			max[1]=a[i];
			k[1]=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(c[i]>max[3]){
			max[3]=c[i];
			k[3]=i;
		}
	}
	if(max[1]>max[3]){
		myz+=max[1];
		ar+=1;
		a[k[1]]=0;
		b[k[1]]=0;
		c[k[1]]=0;
	}
	else if(max[3]>max[1]){
		myz+=max[3];
		cr+=1;
		a[k[3]]=0;
		b[k[3]]=0;
		c[k[3]]=0;
	}
}
else if(cr==n/2 && ar<n/2 && br<n/2){
	for(int i=1;i<=n;i++){
		if(a[i]>max[1]){
			max[1]=a[i];
			k[1]=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]>max[2]){
			max[2]=b[i];
			k[2]=i;
		}
	}
	if(max[1]>max[2]){
		myz+=max[1];
		ar+=1;
		a[k[1]]=0;
		b[k[1]]=0;
		c[k[1]]=0;
	}
	else if(max[2]>max[1]){
		myz+=max[2];
		br+=1;
		a[k[2]]=0;
		b[k[2]]=0;
		c[k[2]]=0;
	}
}
}
return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		answer();
		cout<<myz<<endl;
	}
	return 0;
}
