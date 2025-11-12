#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005][15];
int s[100005][15];
int maxn;
void dfs(int a1,int a2,int a3,int sum,int i){
	if(i>n){
		maxn=max(maxn,sum);
		return;
	}
	if(a1<n/2){
		dfs(a1+1,a2,a3,sum+a[i][1],i+1);
	}
	if(a2<n/2){
		dfs(a1,a2+1,a3,sum+a[i][2],i+1);
	}
	if(a3<n/2){
		dfs(a1,a2,a3+1,sum+a[i][3],i+1);
	}
	return;
} 
bool cmp(int x,int y){
	return x>y;
}
bool cmp1(int x,int y){
	return a[x][1]<a[y][1];
}
bool cmp2(int x,int y){
	return a[x][2]<a[y][2];
}
bool cmp3(int x,int y){
	return a[x][3]<a[y][3];
}
int f1(int i){
	if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
		return 1;
	}
	if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
		return 2;
	}
	if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
		return 3;
	}
}
int f2(int i){
	if(a[i][1]<=a[i][2]&&a[i][1]>=a[i][3]){
		return 1;
	}
	if(a[i][1]<=a[i][3]&&a[i][1]>=a[i][2]){
		return 1;
	}
	if(a[i][2]<=a[i][1]&&a[i][2]>=a[i][3]){
		return 2;
	}
	if(a[i][2]<=a[i][3]&&a[i][2]>=a[i][1]){
		return 2;
	}
	if(a[i][3]<=a[i][1]&&a[i][3]>=a[i][2]){
		return 3;
	}
	if(a[i][3]<=a[i][2]&&a[i][3]>=a[i][1]){
		return 3;
	}
}
int f3(int i){
	if(a[i][1]<=a[i][2]&&a[i][1]<=a[i][3]){
		return 1;
	}
	if(a[i][2]<=a[i][1]&&a[i][2]<=a[i][3]){
		return 2;
	}
	if(a[i][3]<=a[i][1]&&a[i][3]<=a[i][2]){
		return 3;
	}
}
int AC(){
	vector<int> v[5];
	for(int i=1;i<=n;i++){
//		cout<<i<<"\n";
		s[i][1]=f1(i),s[i][2]=f2(i),s[i][3]=f3(i);
//		cout<<s[i][1]<<" "<<s[i][2]<<" "<<s[i][3]<<"\n";
		if(v[s[i][1]].size()==n/2){
			if(s[v[s[i][1]][0]][4]==3){
//				cout<<"F1 ";
				v[s[i][2]].push_back(i);
				if(s[i][2]==1){
					sort(v[s[i][2]].begin(),v[s[i][2]].end(),cmp1);
				}
				else if(s[i][2]==2){
					sort(v[s[i][2]].begin(),v[s[i][2]].end(),cmp2);
				}
				else{
					sort(v[s[i][2]].begin(),v[s[i][2]].end(),cmp3);
				}
				s[i][4]=2;
			}
			else{
				if(a[i][s[i][1]]+a[v[s[i][1]][0]][s[v[s[i][1]][0]][4]+1]<=a[i][s[i][2]]+a[v[s[i][1]][0]][s[v[s[i][1]][0]][4]]){
//					cout<<"F2 ";
					v[s[i][2]].push_back(i);
					if(s[i][2]==1){
						sort(v[s[i][2]].begin(),v[s[i][2]].end(),cmp1);
					}
					else if(s[i][2]==2){
						sort(v[s[i][2]].begin(),v[s[i][2]].end(),cmp2);
					}
					else{
						sort(v[s[i][2]].begin(),v[s[i][2]].end(),cmp3);
					}
					s[i][4]=2;
				}
				else{
//					cout<<"F3 ";
					s[v[s[i][1]][0]][4]+=1;
//					cout<<"A";
//					cout<<v[s[i][1]][0]<<" "<<s[v[s[i][1]][0]][4]<<" "<<s[v[s[i][1]][0]][s[v[s[i][1]][0]][4]];
					v[s[v[s[i][1]][0]][s[v[s[i][1]][0]][4]]].push_back(v[s[i][1]][0]);
//					cout<<"A";
					if(s[v[s[i][1]][0]][s[v[s[i][1]][0]][4]]==1){
						sort(v[s[v[s[i][1]][0]][s[v[s[i][1]][0]][4]]].begin(),v[s[v[s[i][1]][0]][s[v[s[i][1]][0]][4]]].end(),cmp1);
					}
					else if(s[v[s[i][1]][0]][s[v[s[i][1]][0]][4]]==2){
						sort(v[s[v[s[i][1]][0]][s[v[s[i][1]][0]][4]]].begin(),v[s[v[s[i][1]][0]][s[v[s[i][1]][0]][4]]].end(),cmp2);
					}
					else{
						sort(v[s[v[s[i][1]][0]][s[v[s[i][1]][0]][4]]].begin(),v[s[v[s[i][1]][0]][s[v[s[i][1]][0]][4]]].end(),cmp3);
					}
//					cout<<"A";
					v[s[i][1]].erase(v[s[i][1]].begin());
//					cout<<"A";
					v[s[i][1]].push_back(i);
//					cout<<"A";
					if(s[i][1]==1){
						sort(v[s[i][1]].begin(),v[s[i][1]].end(),cmp1);
					}
					else if(s[i][1]==2){
						sort(v[s[i][1]].begin(),v[s[i][1]].end(),cmp2);
					}
					else{
						sort(v[s[i][1]].begin(),v[s[i][1]].end(),cmp3);
					}
//					cout<<"A";
					s[i][4]=1;
				}
			} 
		}
		else{
//			cout<<"F4 ";
			v[s[i][1]].push_back(i);
			if(s[i][1]==1){
				sort(v[s[i][1]].begin(),v[s[i][1]].end(),cmp1);
			}
			else if(s[i][2]==2){
				sort(v[s[i][1]].begin(),v[s[i][1]].end(),cmp2);
			}
			else{
				sort(v[s[i][1]].begin(),v[s[i][1]].end(),cmp3);
			}
			s[i][4]=1;
		}
//		cout<<"OK\n";
	}
	int ans=0;
	for(int i=1;i<=3;i++){
		for(int j:v[i]){
			ans+=a[j][i];
		}
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n>16){
			cout<<AC()<<"\n";
			continue;
		}
		maxn=0;
		dfs(0,0,0,0,1);
		cout<<maxn<<"\n";
	}
	return 0;
	/*
	while(1){
		cout<<"RP++\n";
	}
	*/ 
}

