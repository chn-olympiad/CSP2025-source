#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	int m;
	int k;
	int count=10000;
	int a[100000][3];
	vector<int> b;
	int z=0;
	cin>>n>>m>>k;
	bool city[n][2]={false};
	for(int i=0;i<m;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n+1;i++){
		cin>>b[i];
	}
	for(int j=0;j<m;j++){
		for(int i=0;i<m;i++){
		    if(a[i][2]<count&&city[i][0]==false&&city[i][1]==false){
			    count=a[i][2];
			    for(int g=0;g<m;g++){
				    if(a[g][2]==count){
					    city[i][0]=true;
					    city[i][1]=true;
					    z=z+count;
					    count=10000;
				    }
			    }
		    }
	    }
	}
	for(int j=0;j<m;j++){
		for(int i=0;i<m;i++){
		    if(a[i][2]<count&&city[i][1]==false){
			    count=a[i][2];
			    for(int g=0;g<m;g++){
				    if(a[g][2]==count){
					    city[i][1]=true;
					    z=z+count;
					    count=10000000;
				    }
			    }
		    }
	    }
	}
	for(int j=0;j<m;j++){
		for(int i=0;i<m;i++){
		    if(a[i][2]<count&&city[i][0]==false){
			    count=a[i][2];
			    for(int g=0;g<m;g++){
				    if(a[g][2]==count){
					    city[i][0]=true;
					    z=z+count;
					    count=10000000;
				    }
			    }
		    }
	    }
	}
	cout<<z<<endl;
	return 0;
}

