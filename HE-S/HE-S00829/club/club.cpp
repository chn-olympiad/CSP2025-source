#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int l,c=0;
	int n;
	int a[n][3];
	int max_list[n];
	int temp[3];
	int mtep=0;
	int max_number=0;
    cin>>l>>n;
	for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
        	cin>>a[i][j];
		}
	}
	for(int t=1;t<=n;t++){
		for(int k=1;k<=3;k++){
			temp[k]=a[t][k];
		}
		mtep=max(temp[1],temp[2]);
		max_number=max(mtep,temp[3]);
		cout<<max_number<<" ";
		//max_list[t]==max_number;
		if(max_list[t]==temp[1]) l[1]+=1;
		if(max_list[t]==temp[2]) l[2]+=1;
		if(max_list[t]==temp[3]) l[3]+=1;
	}

	for(int v=1;v<=n;v++){
		for(int k=1;k<=3;k++){
			temp[k]=a[v][k];
		max_list[t]=max_number;
		cout<<max_list[t]<<" "<<endl;
		if(l[c]>n/2){
			max_list=max_number
			if[l[c]==1]max(temp[2],temp[3]);
			if[l[c]==2]max(temp[1],temp[3]);
			if[l[c]==3]max(temp[1],temp[2]);
		}
		cout<<endl;

		for(int i=1;i<=n;i++){
			cout<<max_list[i]<<" "<<endl;
		}
}
}

/*
for(int i;i<=n;i++){
	end_number+=max_list[i];
	}
*/
	//cout<<end_number<<endl;
	return 0;
}
