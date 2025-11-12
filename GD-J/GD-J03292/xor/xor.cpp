#include<bits/stdc++.h>
using namespace std;
using LL = long long;

LL n,k,ans;
LL a[1000100];

bool cmp(pair<LL,LL> x, pair<LL,LL> y){
	if(x.first != y.first) return x.first < y.first;
	return x.second < y.second;	
}

void solveA(){
	if(k==1)cout << n << '\n';
	if(k==0)cout << (n>>1) << '\n';
}

void solveB(){
	LL ans=0;
	if(k==1){
		for(LL i=0;i<n;i++){
			if(a[i]==1)ans++;
		}
		cout << ans << '\n';
	}
	if(k==0){
		vector<LL>cntNO,cntZero; //cntNearOne,cntZero
		for(LL i=0;i<n-1;i++){
			if(a[i]==1 && a[i+1]==1){
				cntNO.push_back(i);
			}
		}
		for(LL i=0;i<n;i++){
			if(a[i]==0)cntZero.push_back(i);
		}
		
		ans=cntNO.size()+cntZero.size();cout << ans << '\n'
	}
	
}

void solveAll(){
	LL ans=0;vector<pair<LL,LL>> vt;vector<LL> dirK; // 答案数，可以为答案的区间，K的位置  
	//计算列表中有多少个k，这样可以直接算出占用最小数据量的数 
	for(LL i=0;i<n;i++)if(a[i]==k){ans++;dirK.push_back(i);}
	//计算区间：用双重for循环  
	for(LL i=0;i<n;i++){
		LL xorcnt=a[i];
		for(LL j=i+1;j<n;j++){
			xorcnt = xorcnt^a[j];
			 if(xorcnt==k){
				vt.push_back({i,j});
			}
		}
	}
	 
	
	//整理结果  
	sort(vt.begin(),vt.end(),cmp);
	for(LL i=0;i<vt.size();i++){
		bool flag=false;
		for(LL j=0;j<dirK.size();j++){
			if(dirK[j] >= vt[i].first && dirK[j] <= vt[i].second){
				flag=true;
				break;
			}	
		}
		for(LL j=i+1;j<vt.size();j++){
			if(vt[i].first == vt[j].first || vt[i].second== vt[j].second || (vt[i].second >= vt[j].first)){
				flag=true;
				break; 
			}
		}
		if(!flag){
			ans++;
		}
	}
	cout << ans << '\n'; 
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	bool spA=true,spB=true;
	for(LL i=0;i<n;i++){
		cin >> a[i];
		if(a[i]!=1)spA=false;
		if(a[i]>1)spB=false;
	}
	
	if(spA=true){
		solveA();
	}else if(spB=true){
		solveB();
	}else{
		solveAll();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

