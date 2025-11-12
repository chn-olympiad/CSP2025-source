#include <bits/stdc++.h>
using namespace std;
struct node{
    int B1,B2,B3;
}club[100000];
int T,N;
int menbers(int lca,int lcb,int lcc,int NN,int I,int menber){
	if(I==N) return menber;
	if(club[I].B1>club[I].B2&&club[I].B1>club[I].B3&&lca+1<=NN/2){
		lca++;
		menber+=club[I].B1;
		int R=menbers(lca,lcb,lcc,NN,I+1,menber);
		if(R!=0) return R;
	}
	if(club[I].B2>club[I].B3&&lcb+1<=NN/2){
		lcb++;
		menber+=club[I].B2;
		int R=menbers(lca,lcb,lcc,NN,I+1,menber);
		if(R!=0) return R;
	}
	if(lcc+1<=NN/2){
		lcc++;
		menber+=club[I].B3;
		int R=menbers(lca,lcb,lcc,NN,I+1,menber);
		if(R!=0) return R;
	}

	if(club[I].B1>club[I].B2&&lca+1<=NN/2){
		lca++;
		menber+=club[I].B1;
		int R=menbers(lca,lcb,lcc,NN,I+1,menber);
		if(R!=0) return R;
	}
	if(lcb+1<=NN/2){
		lcb++;
		menber+=club[I].B2;
		int R=menbers(lca,lcb,lcc,NN,I+1,menber);
		if(R!=0) return R;
	}

	return 0;

}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        for(int j=0;j<N;j++){
            cin>>club[j].B1>>club[j].B2>>club[j].B3;
        }
        cout<<menbers(0,0,0,N,0,0)<<endl;


    }
    fclose(stdin);
    fclose(stdout);
	return 0;
}
