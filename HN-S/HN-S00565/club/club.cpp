#include<bits/stdc++.h>
using namespace std;

int find(int n,int a[4]){
	for(int i=1;i<4;i++){
		if(n==a[i])return i;
	}
	return -1;
}
int mid(int a,int b,int c){
	return max(max(min(a,b),min(b,c)),min(a,c));	
}
int minn(int a,int b,int c){
	return min(min(a,b),c);
}
int maxn(int a,int b,int c){
	return max(max(a,b),c);
}


void func(){
	int n,max[100010],ans=0, a[100010][4];;
	int w[4]={0,0,0,0};
	cin>>n;
		
	for(int i=0;i<n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			if(max[i]<a[i][j])max[i]=a[i][j];
		
		}
	}
	for(int h=n-1;h>0;h--){
		for(int l=0;l<h;l++){
			if(((a[l][1]>a[l+1][1] ||a[l][2]>a[l+1][2] ||a[l][3]>a[l+1][3]))){
				swap(a[l][1],a[l+1][1]);
				swap(a[l][2],a[l+1][2]);
				swap(a[l][3],a[l+1][3]);
			}
			if((find(0,a[l])!=-1||find(0,a[l+1])!=-1)){
				swap(a[l][1],a[l+1][1]);
				swap(a[l][2],a[l+1][2]);
				swap(a[l][3],a[l+1][3]);
			}
			if((find(0,a[l])!=-1&&find(0,a[l+1])==-1)){
				swap(a[l][1],a[l+1][1]);
				swap(a[l][2],a[l+1][2]);
				swap(a[l][3],a[l+1][3]);
			}
			if((find(0,a[l+1])!=-1&&find(0,a[l])==-1)){
				swap(a[l][1],a[l+1][1]);
				swap(a[l][2],a[l+1][2]);
				swap(a[l][3],a[l+1][3]);
			}
		}
	}/*
	for(int i=0;i<n;i++){
		for(int j=1;j<=3;j++){
			cout<<a[i][j]<<" ";
		
		}cout<<endl;
	}*/
	for(int i=0;i<n;i++){
			int finded=find(maxn(a[i][1],a[i][2],a[i][3]),a[i]);
			int finded2=find(mid(a[i][1],a[i][2],a[i][3]),a[i]);
			int finded3=find(minn(a[i][1],a[i][2],a[i][3]),a[i]);
			if(w[finded]<n/2){
				w[finded]+=1;
				ans+=maxn(a[i][1],a[i][2],a[i][3]);
			}else if(w[finded2]<n/2){
				w[finded2]+=1;
				ans+=mid(a[i][1],a[i][2],a[i][3]);
			}else if(w[finded3]<n/2){
				w[finded3]+=1;
				ans+=minn(a[i][1],a[i][2],a[i][3]);
			}
			//cout<<ans<<" "<<finded<<" "<<finded2<<" "<<finded3<<" "<<maxn(a[i][1],a[i][2],a[i][3])<<" "<<mid(a[i][1],a[i][2],a[i][3])<<" "<<minn(a[i][1],a[i][2],a[i][3])<<" "<<w[1]<<","<<w[2]<<","<<w[3]<<endl;
		
		
	}cout<<ans<<endl;
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		func();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
