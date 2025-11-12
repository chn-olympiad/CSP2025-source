#include<bits/stdc++.h>
using namespace std;
int sch[3];
bool xue[100005]; 
struct student{
	int num;
	int id;
	int school; 
	
	
};
student a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,x;
	cin>>n;
	int number,an=0;
	for(int i=0;i<n;i++){
		cin>>x;
		memset(xue,0,100005);
		memset(sch,0,100005);
		int t=0;
		an=0;
		bool teshu_a=true,teshu_b=true;
		for(int j=0;j<x;j++){
			cin>>number;
			a[t].num=number;
			a[t].id=j;
			a[t].school=1;
			t++;
			cin>>number;
			a[t].num=number;
			a[t].id=j;
			a[t].school=2;
			if(number!=0){
				teshu_a=false;
			}
			t++;
			cin>>number;
			a[t].num=number;
			a[t].id=j;
			a[t].school=3;
			if(number!=0){
				teshu_a=false;
				teshu_b=false;
			}
			t++;
		}
		
		for(int j=0;j<x*3;j++){
			for(int z=0;z<(x*3)-j;z++){
				if(a[z].num<a[z+1].num){
					student p=a[z+1];
					a[z+1]=a[z];
					a[z]=p;
				}
			}
		}
		if(teshu_a){
			for(int j=0;j<x/2;j++){
				an+=a[j].num;
			}
			cout<<an<<endl;
			continue;
		}
		for(int j=0;j<x*3;j++){
			if(sch[a[j].school]<x/2 && !xue[a[j].id]){
				an+=a[j].num;
				sch[a[j].school]++;
				xue[a[j].id]=true;
			}
		}
		cout<<an<<endl;
	}
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
