#include<bits/stdc++.h>
using namespace std;
#define ll long long
//vector<int> ch;
int zuihou[101];
int chg[101],mix,beif;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,tmp,idf,xiaor,jxiaor=0;//n––  m¡– £ª 
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>tmp;
		idf++;
		chg[i]=tmp;
	}int bigest=chg[0],lowest=chg[idf];
	xiaor=chg[0];
	for(int i=0;i<idf;i++) {
		for(int j=i+1;j<idf;j++){
			if(chg[j]>bigest){
				beif=bigest;
				if(beif!=xiaor) {
					xiaor=beif;
				}
				bigest=chg[j];
				chg[j]=beif;
			}
		}
		zuihou[i]=bigest;
		chg[idf]=bigest;
	}//≈≈–Ú 
	int cnt=0;
	for(int i=0;i<idf;i++){
		if (chg[i]!=xiaor) cnt++;
		else{
			break;
		}
	}
	int xiaorn,xiaorm,num=0;
	for(int i=n;i>0;i--){
		for(int j=m;j>0;j--){
			num++;
			if(num==cnt) cout<<i<<" "<<j;
		}
	}
//	for(int i=0;i<idf;i++){
//		cout<<chg[i+1]<<endl;
//	}


	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

