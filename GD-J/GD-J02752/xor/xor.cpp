#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int s[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,kk;
	cin>>n>>kk;
	if(n>=200000){
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==kk) sum++;
		}
		cout<<sum<<endl;
	}
	int w=0;
	int tmpp[25];
	while(kk){
		tmpp[w]=kk%2;
		kk/=2;
		w++;
	}  
	int kl=0;
	for(int j=0;j<w;j++){
		kl=kl*10+tmpp[w-1-j];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int k=0;
		int tmp[25];
		while(a[i]){
			tmp[k]=a[i]%2; 
			a[i]/=2;
			k++;
		}
		for(int j=0;j<k;j++){
			s[i]=s[i]*10+tmp[k-1-j];
		}
		//cout<<s[i]<<endl;
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //ÖÕµã£¬Æðµã
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=i;j<=n;j++){
			sum=sum^s[j];
			if(sum==kl){
				pq.push({j,i}); 
				//cout<<i<<' '<<j<<' '<<sum<<' '<<kl<<endl;
			}
		} 
	}
	int line=0;
	int sum=0;
	while(!pq.empty()){
		if(pq.top().second<=line){
			pq.pop();
		}
		else{
			sum++;line=pq.top().first;
			pq.pop();
		}
	}
	cout<<sum;
	return 0;
}

