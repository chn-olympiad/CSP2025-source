#include<bits/stdc++.h>
using namespace std;
int n,k,a[500000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	if(k==0){
		int cnt=0;
		bool bk1=0,bk2=0;
		for(int i=0;i<n;i++){
			if(a[i]==0)cnt++;
			if(a[i]==1&&bk1==1)cnt=cnt+1,bk1=0;
			else if(a[i]==1&&bk1==0)bk1=1;
			else if(a[i]==2&&bk2==1)cnt=cnt+1,bk2=0;
			else if(a[i]==2&&bk2==0)bk2=1;
		}
		cout<<cnt;
	}
	else if(k==1){
		int cnt=0;
		int d;bool bk=0;
		for(int i=0;i<n;i++){
			if(a[i]==1)cnt++;
			if(a[i]!=d&&bk==1)d=-1,bk=0,cnt+=1;
			else if(bk==0)d=a[i],bk=1;
		}
		cout<<cnt;
	}
}
//Jl-J00031#Shang4Shan3Ruo6Shui4
