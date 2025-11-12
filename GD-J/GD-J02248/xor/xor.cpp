#include <bits/stdc++.h>

using namespace std;
int n,k;
int a[500100];
bool A=true,B=true,C=true;
vector<int> path;
vector<int> path2;
int ans=0;
int solve(int s){
	if(s==path.size()+1){
		if(path.size()>=2){ 
			int cnt2=1;
//			cout<<path.size()<<" "<<path2.size()<<" "<<endl;
			for(int i=0;i<path.size();i++){
				if(path[i]==a[cnt2]){
					cnt2++;
				}else{
					if(i>=1){
						if(path2[i-1]==-1){
							return 0;
						}
					}
					while(path[i]!=a[cnt2]){
						cnt2++;
					}
				}
			}
		} 
		int cnt=0;
		int x=path[0];
		bool pd = true;
		for(int i=0;i<path2.size();i++){
			if(path2[i]==1){
				if(x!=k){
					pd=false;
				}else{
					cnt++;
					x=path[i+1];
				}
			}else{
				x=x^path[i+1];
			}
		}
		if(x!=k){
			pd=false;
		}else{
			cnt++;
		}
		if(pd==false){
//			cout<<"FALSE "<<cnt<<" "<<ans<<endl;
		}else{
//			cout<<path[0];
//			for(int i=0;i<path2.size();i++){
//				if(path2[i]==1){
//					cout<<" | "<<path[i+1];
//				}else{
//					cout<<" "<<path[i+1];
//				}
//			}
//			cout<<" ";
//			cout<<"TRUE "<<cnt<<" "<<ans<<endl;
			ans=max(ans,cnt);
		}
		return 0;
	}
	path2.push_back(-1);
	solve(s+1);
	path2.pop_back();
	path2.push_back(1);
	solve(s+1);
	path2.pop_back();
	return 0;
}
int solve2(int s){
	if(s==n+2){
		if(path.size()==0){
			return 0;
		}
//		cout<<"nums:";
//		for(int i=0;i<path.size();i++){
//			cout<<path[i]<<" ";
//		}
//		cout<<endl;
		solve(2);
		return 0;
	}
	solve2(s+1);
	path.push_back(a[s-1]);
	solve2(s+1);
	path.pop_back();
	return 0;
}
int main(){
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			A=false;
		}
		if(a[i]!=0 &&a[i]!=1){
			B=false;
		}
		if(!(a[i]>=0 && a[i]<=255)){
			C=false;
		}
	}
	if(A==true){
		if(k==0){
			cout<<(1+n)*n/2<<endl;
		}else{
			cout<<0<<endl;
		}
		return 0;
	}else if(B==true){
		int cnt=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					cnt++;
				}else if(a[i]==1&&a[i+1]==1){
					cnt++;
					i+=1;
				}
			}
			cout<<(1+cnt)*cnt/2<<endl;
			return 0;
		}
	}
	solve2(2);
	cout<<ans<<endl;
	return 0;
}

