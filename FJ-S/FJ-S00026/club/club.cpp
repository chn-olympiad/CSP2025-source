#include <bits/stdc++.h>
//final
using namespace std;
int s[100003][3];
int choice[100003];
bool cmp1(pair<int,int> a,pair<int,int> b){
	if(choice[a.second]==1&&choice[b.second]!=1)return 1;
	if(choice[a.second]!=1&&choice[b.second]==1)return 0;
	if(choice)
	return min(s[a.second][0]-s[a.second][1],s[a.second][0]-s[a.second][2])<=min(s[b.second][0]-s[b.second][1],s[b.second][0]-s[b.second][2]);
}
bool cmp2(pair<int,int> a,pair<int,int> b){
	if(choice[a.second]==2&&choice[b.second]!=2)return 1;
	if(choice[a.second]!=2&&choice[b.second]==2)return 0;
	return min(s[a.second][1]-s[a.second][0],s[a.second][1]-s[a.second][2])<=min(s[b.second][1]-s[b.second][0],s[b.second][1]-s[b.second][2]);
}
bool cmp3(pair<int,int> a,pair<int,int> b){
	if(choice[a.second]==3&&choice[b.second]!=3)return 1;
	if(choice[a.second]!=3&&choice[b.second]==3)return 0;
	return min(s[a.second][2]-s[a.second][0],s[a.second][2]-s[a.second][1])<=min(s[b.second][2]-s[b.second][0],s[b.second][2]-s[b.second][1]);
}
bool cmpTWO1(pair<int,int> a,pair<int,int> b){
	return s[a.second][0]-s[a.second][1]<=s[b.second][0]-s[b.second][1];
}
bool cmpTHREE1(pair<int,int> a,pair<int,int> b){
	return s[a.second][0]-s[a.second][2]<=s[b.second][0]-s[b.second][2];
}
bool cmpONE2(pair<int,int> a,pair<int,int> b){
	return s[a.second][1]-s[a.second][0]<=s[b.second][1]-s[b.second][0];
}
bool cmpTHREE2(pair<int,int> a,pair<int,int> b){
	return s[a.second][1]-s[a.second][2]<=s[b.second][1]-s[b.second][2];
}
bool cmpTWO3(pair<int,int> a,pair<int,int> b){
	return s[a.second][2]-s[a.second][1]<=s[b.second][2]-s[b.second][1];
}
bool cmpONE3(pair<int,int> a,pair<int,int> b){
	return s[a.second][2]-s[a.second][0]<=s[b.second][2]-s[b.second][0];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	for(int _ = 0;_<T;++_){
		//bool SPA=1;
		//int SPAANS=0;
		int n = 0;
		cin>>n;
		int c1=0,c2=0,c3=0;
		int ans=0;
		for(int i = 0;i<n;++i){
			s[i][0]=0;
			s[i][1]=0;
			s[i][2]=0;
			scanf("%d%d%d",&s[i][0],&s[i][1],&s[i][2]);
			//if(SPA&&s[i][0]==0&&s[i][1]==0);
			//else if(s[i][0]==0&&s[i][2]==0);
			//else if(s[i][1]==0&&s[i][2]==0);
			//else SPA=0;
			if(s[i][0]>=s[i][1]&&s[i][0]>=s[i][2]){
				++c1;
				ans+=s[i][0];
				choice[i]=1;
			}
			else if(s[i][1]>=s[i][2]){
				++c2;
				ans+=s[i][1];
				choice[i]=2;
			}
			else{
				++c3;
				ans+=s[i][2];
				choice[i]=3;
			} 
		}
		int t = n / 2;
		//if(SPA){
		//	int tmp[n+3];
		//	for(int i = 0;i<n;++i)tmp[i]=max(max(s[i][0],s[i][1]),s[i][2]);
		//	if(c1>t)
		//}
		if(c1>t||c2>t||c3>t){
			
			if(c1>t){
				pair<bool,int> temp[n+3];
				for(int i = 0;i<n;++i){
					temp[i].second=i;
					temp[i].first=0;
				}
				sort(temp,temp+n,cmp1);
				int cg = 0;
				int ch2=0,ch3=0;
				int k = 0;
				while((c1-cg)>t){
					if(s[temp[cg].second][0]-s[temp[cg].second][1]<=s[temp[cg].second][0]-s[temp[cg].second][2]){
						if(ch2+1+c2<=t){
							ans-=(s[temp[cg].second][0]-s[temp[cg].second][1]);
							++ch2;
							//cout<<"&"<<cg<<" "<<s[temp[cg].second][0]<<"¡¡"<<s[temp[cg].second][1]<<" "<<s[temp[cg].second][2]; 
						}
						else{
							k=3;
							break;
						}
					}
					else{
						if(ch3+1+c3<=t){
							ans-=(s[temp[cg].second][0]-s[temp[cg].second][2]);
							++ch3;
						}
						else{
							k=2;
							break;
						}
					}
					++cg;
				}
				if(k==3){
					sort(temp+cg,temp+n,cmpTHREE1);
					while((c1-cg)>t){
						ans-=(s[temp[cg].second][0]-s[temp[cg].second][2]);
						++cg;
					}
				}
				if(k==2){
					sort(temp+cg,temp+n,cmpTWO1);
					while((c1-cg)>t){
						ans-=(s[temp[cg].second][0]-s[temp[cg].second][1]);
						++cg;
					}
				}
			}
			
			
			
			
			
			
			
			
			
			
			if(c2>t){
				pair<int,int> temp[n+3];
				for(int i = 0;i<n;++i){
					temp[i].second=i;
					temp[i].first=0;
				}
				sort(temp,temp+n,cmp2);
				int cg = 0;
				int ch1=0,ch3=0;
				int k = 0;
				while((c2-cg)>t){
					if(s[temp[cg].second][1]-s[temp[cg].second][0]<=s[temp[cg].second][1]-s[temp[cg].second][2]){
						if(ch1+1+c1<=t){
							ans-=(s[temp[cg].second][1]-s[temp[cg].second][0]);
							++ch1;
						}
						else{
							k=3;
							break;
						}
					}
					else{
						if(ch3+1+c3<=t){
							ans-=(s[temp[cg].second][1]-s[temp[cg].second][2]);
							++ch3;
						}
						else{
							k=1;
							break;
						}
					}
					++cg;
				}
				if(k==3){
					sort(temp+cg,temp+n,cmpTHREE2);
					while((c2-cg)>t){
						ans-=(s[temp[cg].second][1]-s[temp[cg].second][2]);
						++cg;
					}
				}
				if(k==1){
					sort(temp+cg,temp+n,cmpONE2);
					while((c2-cg)>t){
						ans-=(s[temp[cg].second][1]-s[temp[cg].second][0]);
						++cg;
					}
				}
			}
			
			
			
			
			if(c3>t){
				pair<int,int> temp[n+3];
				for(int i = 0;i<n;++i){
					temp[i].second=i;
					temp[i].first=0;
				}
				sort(temp,temp+n,cmp3);
				int cg = 0;
				int ch1=0,ch2=0;
				int k = 0;
				while((c3-cg)>t){
					if(s[temp[cg].second][2]-s[temp[cg].second][0]<=s[temp[cg].second][2]-s[temp[cg].second][1]){
						if(ch1+1+c1<=t){
							ans-=(s[temp[cg].second][2]-s[temp[cg].second][0]);
							++ch1;
						}
						else{
							k=2;
							break;
						}
					}
					else{
						if(ch2+1+c2<=t){
							ans-=(s[temp[cg].second][2]-s[temp[cg].second][1]);
							++ch2;
						}
						else{
							k=1;
							break;
						}
					}
					++cg;
				}
				if(k==2){
					sort(temp+cg,temp+n,cmpTWO3);
					while((c3-cg)>t){
						ans-=(s[temp[cg].second][2]-s[temp[cg].second][1]);
						++cg;
					}
				}
				if(k==1){
					sort(temp+cg,temp+n,cmpONE3);
					while((c3-cg)>t){
						ans-=(s[temp[cg].second][2]-s[temp[cg].second][0]);
						++cg;
					}
				}
			}
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		}
		cout<<ans<<endl;
			
		}
		
	
	fclose(stdin);
	fclose(stdout);

	return 0;
} 
