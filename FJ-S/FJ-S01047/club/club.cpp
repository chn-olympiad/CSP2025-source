#include<iostream>
using namespace std;
const int MAX_N=100001;
int m=0,club01[MAX_N]={},club02[MAX_N]={},club03[MAX_N]={},o[MAX_N]={},c[MAX_N][3]={};
int p[MAX_N][3]={};
void sort(int club[MAX_N]){
	for(int i=m;i>=1;i--){
		for(int j=1;j<=i;i++){
			if(club[j]>club[j+1]){
				swap(club[j],club[j+1]);
			}
		}
	}
}
int put(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(club01[i]==c[j][0]){
				p[i][0]=j;
			}
			else if(club02[i]==c[j][1]){
				p[i][1]=j;
			}
			else if(club03[i]==c[j][1]){
				p[i][2]=j;
			}
		}
	}
}
int maxx(int x,int y,int z){
	if(x==y==z){
		return x;
	}
	if(x==y){
		return x>z?x:z;
	}
	if(x==z){
		return x>y?x:y;
	}
	if(y==z){
		return y>z?y:z;
	}
	return (x>y?x:y)>z?(x>y?x:y):z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		int r=0,s=0,t=0,a1=0,a2=0,a3=0;
		m=0,club01[MAX_N]={},club02[MAX_N]={},club03[MAX_N]={},o[MAX_N]={};
		cin >> m;
		for(int j=1;j<=m;j++){
			cin >> club01[j];
			cin >> club02[j];
			cin >> club03[j];
		}
		sort(club01);
		sort(club02);
		sort(club03);
		for(int j=1;j<=m;j++){
				if(maxx(club01[r],club02[s],club03[t])==club01[r]){
				if(a1<m/2){
					o[j]=club01[r];
					p[r][0]=-1;p[r][1]=-1;p[r][2]=-1;
					while(p[r][0]<0){
						r++;
					}
					a1++;
					
				}
				else{
					if(club02[s]>club03[t]){
						if(a2<m/2){
							o[j]=club02[s];
							p[s][0]=-1;p[s][1]=-1;p[s][2]=-1;
							while(p[s][1]<0){
								s++;
							}
							a2++;
						}
						else{
							break;
						}
					}
					else{
						if(a3<m/2){
							o[j]=club03[t];
							t++;
						}
						else{
							break;
						}
					}
				}
			}
			else if(maxx(club01[r],club02[s],club03[t])==club02[s]){
				
				if(a2<m/2){
					o[j]=club02[s];
					p[s][0]=-1;p[s][1]=-1;p[s][2]=-1;
					while(p[s][1]<0){
						s++;
					}
					a2++;
				}
				else{
					if(club01[r]>club03[t]){
						if(a1<m/2){
							o[j]=club01[r];
							p[r][0]=-1;p[r][1]=-1;p[r][2]=-1;
							while(p[r][0]<0){
								r++;
							}
							a1++;
						}
						else{
							break;
						}
					}
					else{
						if(a3<m/2){
							o[j]=club03[t];
							p[t][0]=-1;p[t][1]=-1;p[t][2]=-1;
							while(p[t][2]<0){
								t++;
							}
							a3++;
						}
						else{
							break;
						}
					}
				}
			}
			else if(maxx(club01[r],club02[s],club03[t])==club03[t]){
				if(a3<m/2){
					o[j]=club03[t];
					p[t][0]=-1;p[t][1]=-1;p[t][2]=-1;
					while(p[t][2]<0){
						t++;
					}
					a3++;
				}
				else{
					if(club01[r]>club02[s]){
						if(a1<m/2){
							o[j]=club01[r];
							p[r][0]=-1;p[r][1]=-1;p[r][2]=-1;
							while(p[r][0]<0){
								r++;
							}
							a1++;
						}
						else{
							break;
						}}
					else{
						if(a2<m/2){
							o[j]=club02[s];
							p[s][0]=-1;p[s][1]=-1;p[s][2]=-1;
							while(p[s][2]<0){
								s++;
							}
							a2++;
						}
						else{
							break;
						}
					}
				}
			}
		
	}
		
			
		
		int ans=0;
		for(int j=1;j<=m;j++){
			ans+=o[j];
		}
		cout << ans;
	}
	return 0;}
