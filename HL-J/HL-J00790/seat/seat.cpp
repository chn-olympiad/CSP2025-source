#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,i,j,people_,ans=0,num,x,y,R=1;
	bool cmp=true;
	vector<int> people;
	
	cin>>n>>m;
	num=m*n;
	for(i=1;i<=num;i++){
		cin>>people_;
		
		people.push_back(people_);
		ans++;
	}
	people.push_back(0);

	int max=INT_MIN;
	cout<<"ok";
	while(1){
		
		for(j=0;j<=ans;j++){
			if(j==0){
				max=people[j];
			} else if(max<people[j]){
				cmp=false;
			}
		}
		
		if(cmp){
			break;
		}else{
			for(j=0;j<=ans;j++){
				if(people[i]>=people[i+1]){
					continue;
				}else{
					if(i==R){
						R++;
					}
					people_=people[j];
					people[j]=people[j+1];
					people[j+1]=people_;
				}
			}
		}
		
		
	}
	cout<<1;
	
	x=people[R]/n;
	y=people[R]%m;
	
	cout<<m<<" "<<n;
		
	return 0;
}
