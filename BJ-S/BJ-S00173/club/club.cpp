#include <bits/stdc++.h>
using namespace std;
int a[100010][4];
int n;
int answer;
void force(int depth,int amazing,int l1,int l2,int l3){
	if (depth==n+1){
		answer=max(answer,amazing);
		return;
	}
	if (l1!=n/2)
		force(depth+1,amazing+a[depth][1],l1+1,l2,l3);
	if (l2!=n/2)
		force(depth+1,amazing+a[depth][2],l1,l2+1,l3);
	if (l3!=n/2)
		force(depth+1,amazing+a[depth][3],l1,l2,l3+1);
}
void binaryforcefornone1(int depth,int amazing,int l1,int l2,int l3){
	answer=max(answer,amazing);
	binaryforcefornone1(depth+1,amazing+a[depth][2],l1,l2+1,l3);
	binaryforcefornone1(depth+1,amazing+a[depth][3],l1,l2,l3+1);
}
void binaryforcefornone2(int depth,int amazing,int l1,int l2,int l3){
	answer=max(answer,amazing);
	binaryforcefornone2(depth+1,amazing+a[depth][1],l1+1,l2,l3);
	binaryforcefornone2(depth+1,amazing+a[depth][3],l1,l2,l3+1);
}
void binaryforcefornone3(int depth,int amazing,int l1,int l2,int l3){
	answer=max(answer,amazing);
	binaryforcefornone3(depth+1,amazing+a[depth][1],l1+1,l2,l3);
	binaryforcefornone3(depth+1,amazing+a[depth][2],l1,l2+1,l3);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	//Accepted is hard and impossible. Get 25 pts is hard but possible.
	int t;
	cin>>t;
	while (t--){
		cin>>n;
		int Asum=0,Bsum=0,Csum=0;
		for (int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			Asum+=a[i][1];
			Bsum+=a[i][2];
			Csum+=a[i][3];
		}
		if (Bsum==Csum&&Csum==0){
			vector<int>vec;
			for (int i=1;i<=n;i++)
				vec.push_back(a[i][1]);
			sort(vec.begin(),vec.end(),greater<int>());
			int sum=0;
			for (int i=0;i<n/2;i++)
				sum+=vec[i];
			cout<<sum<<endl;
			continue;
		}
		if (Asum==Csum&&Csum==0){
			vector<int>vec;
			for (int i=1;i<=n;i++)
				vec.push_back(a[i][2]);
			sort(vec.begin(),vec.end(),greater<int>());
			int sum=0;
			for (int i=0;i<n/2;i++)
				sum+=vec[i];
			cout<<sum<<endl;
			continue;
		}
		if (Bsum==Asum&&Asum==0){
			vector<int>vec;
			for (int i=1;i<=n;i++)
				vec.push_back(a[i][3]);
			sort(vec.begin(),vec.end(),greater<int>());
			int sum=0;
			for (int i=0;i<n/2;i++)
				sum+=vec[i];
			cout<<sum<<endl;
			continue;
		}
		if (Asum==0){
			vector<pair<int,int>>A;
			for (int i=1;i<=n;i++)
				A.push_back({a[i][3],i});
			vector<pair<int,int>>B;
			for (int i=1;i<=n;i++)
				B.push_back({a[i][2],i});
			sort(A.begin(),A.end(),greater<pair<int,int>>());
			sort(B.begin(),B.end(),greater<pair<int,int>>());
			vector<pair<pair<int,int>,bool>>C;
			int i=0,j=0;
			while (i<=n&&j<=n){
				if (A[i].first>B[j].first)
					C.push_back(make_pair(A[i++],false));
				else
					C.push_back(make_pair(B[j++],true));
			}
			while (i<=n)
				C.push_back(make_pair(A[i++],false));
			while (j<=n)
				C.push_back(make_pair(B[j++],false));
			map<int,bool>disable;
			int sum=0;
			int TAsum=0,TBsum=0;
			for (auto i:C){
				if (sum==n-(n&1)) break;
				if (disable[i.first.second]==false&&!i.second&&TAsum!=n/2){
					TAsum++;
					sum++;
					answer+=i.first.first;
					disable[i.first.second]=true;
				}
				if (disable[i.first.second]==false&&i.second&&TBsum!=n/2){
					TBsum++;
					sum++;
					answer+=i.first.first;
					disable[i.first.second]=true;
				}
			}
			cout<<answer<<endl;
			answer=0;
			continue;
		}
		if (Bsum==0){
			vector<pair<int,int>>A;
			for (int i=1;i<=n;i++)
				A.push_back({a[i][1],i});
			vector<pair<int,int>>B;
			for (int i=1;i<=n;i++)
				B.push_back({a[i][3],i});
			sort(A.begin(),A.end(),greater<pair<int,int>>());
			sort(B.begin(),B.end(),greater<pair<int,int>>());
			vector<pair<pair<int,int>,bool>>C;
			int i=0,j=0;
			while (i<=n&&j<=n){
				if (A[i].first>B[j].first)
					C.push_back(make_pair(A[i++],false));
				else
					C.push_back(make_pair(B[j++],true));
			}
			while (i<=n)
				C.push_back(make_pair(A[i++],false));
			while (j<=n)
				C.push_back(make_pair(B[j++],false));
			map<int,bool>disable;
			int sum=0;
			int TAsum=0,TBsum=0;
			for (auto i:C){
				if (sum==n-(n&1)) break;
				if (disable[i.first.second]==false&&!i.second&&TAsum!=n/2){
					TAsum++;
					sum++;
					answer+=i.first.first;
					disable[i.first.second]=true;
				}
				if (disable[i.first.second]==false&&i.second&&TBsum!=n/2){
					TBsum++;
					sum++;
					answer+=i.first.first;
					disable[i.first.second]=true;
				}
			}
			cout<<answer<<endl;
			answer=0;
			continue;
		}
		if (Csum==0){
			vector<pair<int,int>>A;
			for (int i=1;i<=n;i++)
				A.push_back({a[i][1],i});
			vector<pair<int,int>>B;
			for (int i=1;i<=n;i++)
				B.push_back({a[i][2],i});
			sort(A.begin(),A.end(),greater<pair<int,int>>());
			sort(B.begin(),B.end(),greater<pair<int,int>>());
			vector<pair<pair<int,int>,bool>>C;
			int i=0,j=0;
			while (i<=n&&j<=n){
				if (A[i].first>B[j].first)
					C.push_back(make_pair(A[i++],false));
				else
					C.push_back(make_pair(B[j++],true));
			}
			while (i<=n)
				C.push_back(make_pair(A[i++],false));
			while (j<=n)
				C.push_back(make_pair(B[j++],false));
			map<int,bool>disable;
			int sum=0;
			int TAsum=0,TBsum=0;
			for (auto i:C){
				if (sum==n-(n&1)) break;
				if (disable[i.first.second]==false&&!i.second&&TAsum!=n/2){
					TAsum++;
					sum++;
					answer+=i.first.first;
					disable[i.first.second]=true;
				}
				if (disable[i.first.second]==false&&i.second&&TBsum!=n/2){
					TBsum++;
					sum++;
					answer+=i.first.first;
					disable[i.first.second]=true;
				}
			}
			cout<<answer<<endl;
			answer=0;
			continue;
		}
		if (n<=18){
			force(1,0,0,0,0);
			cout<<answer<<endl;
			answer=0;
			continue;
		}
		if (true){
			vector<pair<pair<int,int>,int>>T;
			for (int i=1;i<=n;i++)
				T.push_back({{a[i][1],i},Asum});
			for (int i=1;i<=n;i++)
				T.push_back({{a[i][2],i},Bsum});
			for (int i=1;i<=n;i++)
				T.push_back({{a[i][3],i},Csum});
			sort(T.begin(),T.end(),greater<pair<pair<int,int>,int>>());
			map<int,bool>disable;
			int sum=0;
			int TAsum=0,TBsum=0,TCsum=0;
			for (auto i:T){
				if (sum==n) break;
				if (disable[i.first.second]==false&&i.second==Asum&&TAsum!=n/2){
					TAsum++;
					sum++;
					answer+=i.first.first;
					disable[i.first.second]=true;
				}
				if (disable[i.first.second]==false&&i.second==Bsum&&TBsum!=n/2){
					TBsum++;
					sum++;
					answer+=i.first.first;
					disable[i.first.second]=true;
				}
				if (disable[i.first.second]==false&&i.second==Csum&&TCsum!=n/2){
					TCsum++;
					sum++;
					answer+=i.first.first;
					disable[i.first.second]=true;
				}
				if (TAsum==n/2&&TAsum==TBsum&&TBsum==TCsum)
					break;
			}
			cout<<answer<<endl;
			answer=0;
			continue;
		}else printf("Bad! It's so bad!");
	}
	return false;
}
