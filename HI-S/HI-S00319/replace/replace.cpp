#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
	freopen("replace.in","r",stdin)
	freopen("replace.out","w",stdout)
    int n;
    cin>>n;
    vector<string>grid(n);
    for(int i=0;i<n;++i)
    {
    	cin>>grid[i];
	}
	vector<vector<bool>>lit(n,vector<bool>(n,false));
	int dirs[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)
		{
			if(grid[i][j]=='*'){
				lit[i][j]=true;
				for(auto&dir:dirs){
					int x=j+dir[0];
					int y=j+dir[1];
					while(x>=0&&x<n&&y>=0&&y<n&&grid[x][y]!='*'){
						lit[x][y]=ture;
						x+=dir[0];
						y+=dir[1];
					}
				}
			}
		}
	}
	int count=0;
	for(auto&row:lit){
		for(bool b:row){
			if(b){
				++count;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}
