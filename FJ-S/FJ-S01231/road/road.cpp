//baka solution

#include<bits/stdc++.h>
#define int long long
using namespace std;

struct road{
	int startPoint=0;
	int endPoint=0;
	int Wight=0;
};

struct village{
	int fixCost=0;
	vector<int> roadWights={};
};

bool roadCmp(road a,road b){
	return a.Wight < b.Wight;
}

int sigmaWights(vector<road> roads){
	int ans=0;
	for(unsigned int i=0;i<roads.size();i++){
		ans+=roads[i].Wight;
	}
	return ans;
}

int optimizeWightsWithVillage(int n,vector<road> originalRoads,vector<village> villages){
	return 0;
}

vector<road> generateMinTree(int n,vector<road> originalRoads){
	vector<bool> isConnected(n,0);
	vector<road> ansRoads;
	int notConnectedNote = n;
	
	sort(originalRoads.begin(),originalRoads.end(),roadCmp);
	for(unsigned int i=0;i<originalRoads.size()&&notConnectedNote>0;i++){
		if( (!isConnected[originalRoads[i].Wight]) || (!isConnected[originalRoads[i].Wight]) ){
			ansRoads.push_back(originalRoads[i]);
			isConnected[originalRoads[i].startPoint]? notConnectedNote-- : isConnected[originalRoads[i].startPoint] = 1;
			isConnected[originalRoads[i].endPoint]?notConnectedNote-- : isConnected[originalRoads[i].endPoint] = 1;
		}
	}
	
	return ansRoads;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k,temp1,temp2,temp3;
	cin>>n>>m>>k;
	vector<road> roads;
	road tempRoad;
	for(int i=0;i<m;i++){
		cin>>temp1>>temp2>>temp3;
		tempRoad.startPoint=temp1;
		tempRoad.endPoint=temp2;
		tempRoad.Wight=temp3;
		roads.push_back(tempRoad);
	}
	vector<village> villages;
	village tempVillage;
	vector<int> tempWights(n);
	for(int i=0;i<k;i++){
		cin>>temp1;
		tempVillage.fixCost=temp1;
		for(int j=0;j<n;j++){
			cin>>temp2;
			tempWights[j]=temp2;
		}
		tempVillage.roadWights = tempWights;
		villages.push_back(tempVillage);
	}
	
	vector<road> minRoadsWithoutVillage = generateMinTree(n,roads);
	int ans = sigmaWights(minRoadsWithoutVillage);
	cout<<ans<<endl;
}
