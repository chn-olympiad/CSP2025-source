#include<iostream>
#include<vector>
#include<map>
#include<windows.h>
using namespace std;
//void bian(vector<int>& ban,int n){
//	if(ban.size()==1){
//		ban[0]++;
//		if(ban[0]>=n){
//			ban.pop_back();
//		}
//		return;
//	}
//	int i=ban.size()-1;
//	ban[i]++;
//	if(ban[i]>=n){
//		ban[i-1]++;
//		ban[i]=ban[i-1]+1;
//		if(ban[i]>n){
//			ban.pop_back();
//		}
//	}
//}

void bian(vector<int>& ban,int n){
	if(ban[0]==n-ban.size()){
		ban.pop_back();
		for(int i=0;i<ban.size();i++){
			ban[i]=i+1;
		}
		return;
	}
	int i=ban.size()-1;
	ban[i]++;
	while(ban[i]>=n){
		ban[i]--;
		n--;
		i--;
		ban[i]++;
	}
	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	int p=2;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=0&&a[i]!=1){
			p=0;
		}if(a[i]==0){
			p=1;
		}
	}
	if(p==2){
		cout<<a.size()/2;
	}else if(p==1){
		map<int,int> b;
		int tans=0;
		for(int i=0;i<n;i++){
			b[a[i]]++;
			if(i!=0){
				if(a[i-1]==1&&a[i]==1){
					tans++;
				}
			}
		}
		if(k==1){
			cout<<b[1];
		}else{
			cout<<b[0]+tans;
		}
	}else{
		vector<int> ban(a.size()-1);
		for(int i=0;i<ban.size();i++){
			ban[i]=i+1;
		}
		int ans=0;
		while(!ban.empty()){
			int tans=0;
			int l=a[0];
			int j=0;
			for(int i=1;i<n;i++){
				if(i==ban[j]){
					j++;
					if(l==k){
						tans++;
					}
					l=a[i];
//					if(ban.size()==2&&ban[0]==2&&ban[1]==3){
//						cout<<"n";
//					}
					continue;
				}
//				if(ban.size()==2&&ban[0]==2&&ban[1]==3){
//					cout<<l<<" "<<a[i]<<" "<<(l^a[i])<<endl;
//				}
				l^=a[i];
			}
			if(l==k){
				tans++;
			}
			if(tans>ans){
				ans=tans;
			}
			bian(ban,a.size());
			
		}
		cout<<ans;
	}
//	cout<<"oisejio";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

