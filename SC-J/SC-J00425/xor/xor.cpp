#include<bits/stdc++.h>
using namespace std;
int n,k,l[5005],sl=0,sums;
bool can(){
	int sum,gs1,gs2;
	int s1[100001],s2[100001],d1,d2;
		d1=l[0];
	for(int i=0;d1!=0;i++){
		s1[i]=d1%2;
		d1=(d1-s1[i])/2;
		gs1++;
	}
	d2=l[1];
	for(int i=0;d2!=0;i++){
		s2[i]=d2%2;
		d2=(d2-s2[i])/2;
		gs2++;
	}
	for(int j=2;j<sl;j++){
		if(gs1>gs2){
			for(int i=gs1;i>0;i--){
				s2[i]=s2[i+gs2-gs1];
			}
			for(int i=gs1-gs2;i>0;i--){
				s2[i]=0;
			}
			for(int i=0;i<gs1;i++){
				if(s1[i]==s2[i]) s1[i]=0;
				else s1[i]=1;
			}
		}
		if(gs2>gs1){
			for(int i=gs2;i>0;i--){
				s1[i]=s1[i+gs1-gs2];
			}
			for(int i=gs2-gs1;i>0;i--){
				s1[i]=0;
			}
			gs1=gs2;
			for(int i=0;i<gs2;i++){
				if(s1[i]==s2[i]) s1[i]=0;
				else s1[i]=1;
			}
		}
		d2=l[j];
		gs2=0;
		for(int i=0;d2!=0;i++){
			s2[i]=d2%2;
			d2=(d2-s2[i])/2;
			gs2++;
		}
	}
	for(int i=0;i<gs1;i++){
		sum=sum+2^i;
	}
	if(sum==k) return 1;
	else return 0;	
};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int a[n],sums=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int x=0;x<j-i;x++){
				l[x]=a[i+x];
				sl++;
			}
			if(can()==1) sums++;
			for(int y=0;y<sl;y++){
				l[y]=0;
			}
			sl=0;
		}
	}
	cout<<sums;
	return 0;
}