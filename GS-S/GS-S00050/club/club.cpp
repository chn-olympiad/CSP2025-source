#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxn_satisfy(vector<int>satisfy);
int maxn(vector<int>satisfy);
int club(vector<int>satisfy);
int club2(vector<int>satisfy);
void half(vector<vector<int>>p,vector<int>g,vector<int>vf,vector<int>vb,int n);
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n; 
	cin>>t>>n; 
	for(int lll=0;lll<t;lll++){
		vector<int>grade(3);
		vector<vector<int>>person;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				int temp;
				cin>>temp;
				grade[j]=temp;
			}
			person.push_back(grade);
		}
		int count_=0;
		vector<int>g_c[2];
		for(int i=0;i<person.size();i++){
			int temp1,temp2;
			temp1=maxn_satisfy(person[i]);
			g_c[0].push_back(temp1);
			temp2=club(person[i]);
			g_c[1].push_back(temp2);
		}
		half(person,grade,g_c[0],g_c[1],n);
		for(int i=0;i<person.size();i++){
			count_=count_+g_c[0][i];
		}
			cout<<count_;
		}
		return 0;
}
void half(vector<vector<int>>p,vector<int>g,vector<int>vf,vector<int>vb,int n){
	for(int j=0;j<vf.size();j++){
		for(int k=0;k<vf.size();k++){
			if(vf[j]>vf[k]){
				swap(vf[j],vf[k]);
				swap(vb[j],vb[k]);
			}
		}
	}
	int count=1;
	for(int i=0;i<vf.size();i++){
		if(vb[i+1]==vb[1]&&i<vb.size()-1){
			count++;
			for(int y=0;y<vf.size();y++){
				if(count>(n/2)){
					for(int j=vf.size()-1;j>=0;j--){
						int temp=maxn(g);
						vf[j]=temp;
						int temp2=club2(g);
						vb[j]=temp2;			
					}
				}
			}
		}
	}
} 
int maxn_satisfy(vector<int>satisfy){
	int maxn=satisfy[0];
	for(int i=0;i<satisfy.size();i++){
		if(satisfy[i+1]>maxn&&i<satisfy.size()-1){
			maxn=satisfy[i+1];
		}
	}
	return maxn;
}
int maxn(vector<int>satisfy){
	int maxn=satisfy[0];
	for(int i=0;i<satisfy.size();i++){
		if(satisfy[i+1]>maxn&&i<satisfy.size()-1){
			maxn=satisfy[i+1];
		}
	}
	for(int i=0;i<satisfy.size();i++){
		if(satisfy[i]!=maxn){
			return satisfy[i];
		}
	}
}
int club(vector<int>satisfy){
	int maxn=satisfy[0];
	for(int i=0;i<satisfy.size();i++){
		if(satisfy[i+1]>maxn&&i<satisfy.size()-1){
			maxn=satisfy[i+1];
		}
	}
	vector<int>temp;
	for(int i=0;i<satisfy.size();i++){
		temp.push_back(satisfy[i]);
	}
	for(int i=0;i<temp.size();i++){
		for(int k=0;k<temp.size();k++){
			if(temp[i]>temp[k]){
				swap(temp[i],temp[k]);
			}
		}
	}
	for(int i=0;i<satisfy.size();i++){
		if(satisfy[i]==temp[0]){
			return i+1;
		}
	}
} 
int club2(vector<int>satisfy){
	int maxn=satisfy[0];
	for(int i=0;i<satisfy.size();i++){
		if(satisfy[i+1]>maxn&&i<satisfy.size()-1){
			maxn=satisfy[i+1];
		}
	}
	vector<int>temp;
	for(int i=0;i<satisfy.size();i++){
		temp.push_back(satisfy[i]);
	}
	for(int i=0;i<temp.size();i++){
		for(int k=0;k<temp.size();k++){
			if(temp[i]>temp[k]){
				swap(temp[i],temp[k]);
			}
		}
	}
	for(int i=0;i<satisfy.size();i++){
		if(satisfy[i]==temp[1]){
			return i+1;
		}
	}
}
int club3(vector<int>satisfy){
	int maxn=satisfy[0];
	for(int i=0;i<satisfy.size();i++){
		if(satisfy[i+1]>maxn&&i<satisfy.size()-1){
			maxn=satisfy[i+1];
		}
	}
	vector<int>temp;
	for(int i=0;i<satisfy.size();i++){
		temp.push_back(satisfy[i]);
	}
	for(int i=0;i<temp.size();i++){
		for(int k=0;k<temp.size();k++){
			if(temp[i]>temp[k]){
				swap(temp[i],temp[k]);
			}
		}
	}
	for(int i=0;i<satisfy.size();i++){
		if(satisfy[i]==temp[2]){
			return i+1;
		}
	}
}
int afs(vector<vector<int>>p,vector<int>g,vector<int>vf,vector<int>vb,int n){
	for(int j=0;j<vf.size();j++){
		for(int k=0;k<vf.size();k++){
			if(vf[j]>vf[k]){
				swap(vf[j],vf[k]);
				swap(vb[j],vb[k]);
			}
		}
	}
	int count=1;
	for(int i=0;i<vf.size();i++){
		if(vb[i+1]==vb[1]&&i<vb.size()-1){
			count++;
			for(int y=0;y<vf.size();y++){
				if(count>(n/2)){
					for(int j=vf.size()-1;j>=0;j--){
						int temp=maxn(g);
						vf[j]=temp;
						int temp2=club3(g);
						vb[j]=temp2;			
					}
				}
			}
		}
	}
}
