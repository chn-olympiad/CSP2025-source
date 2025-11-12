//GZ-S00176 贵阳市第一中学 张轩睿 
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T;
int n;
struct Student{
	int Asub,Bsub,Csub;
	int MaxABC;
	int Maxpos;
}club[N];
struct Node1{
	int Asub,Bsub,Csub;
	bool operator<(const Node1& node)const{
		return max(Bsub,Csub)-Asub<max(node.Bsub,node.Csub)-node.Asub;
	}
};
struct Node2{
	int Asub,Bsub,Csub;
	bool operator<(const Node2& node)const{
		return max(Asub,Csub)-Bsub<max(node.Asub,node.Csub)-node.Bsub;
	}
};

struct Node3{
	int Asub,Bsub,Csub;
	bool operator<(const Node3& node)const{
		return max(Bsub,Asub)-Csub<max(node.Bsub,node.Asub)-node.Csub;
	}
};
priority_queue<Node1>A;
priority_queue<Node2>B;
priority_queue<Node3>C;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%d%d%d",&club[i].Asub,&club[i].Bsub,&club[i].Csub);
			club[i].MaxABC=max(club[i].Asub,max(club[i].Bsub,club[i].Csub));
			if (club[i].Asub==club[i].MaxABC)club[i].Maxpos=1;
			else if (club[i].Bsub==club[i].MaxABC)club[i].Maxpos=2;
			else club[i].Maxpos=3;
		}
		for (int i=1;i<=n;i++){
			int pos=club[i].Maxpos;
			if (pos==1){
				if (A.size()==n/2){
					Node1 Tp=A.top();
					if (max(Tp.Bsub,Tp.Csub)+club[i].Asub>max(club[i].Bsub,club[i].Csub)+Tp.Asub){
						A.pop();A.push({club[i].Asub,club[i].Bsub,club[i].Csub});
						if ((max(Tp.Bsub,Tp.Csub)==Tp.Bsub))B.push({Tp.Asub,Tp.Bsub,Tp.Csub});
						else C.push({Tp.Asub,Tp.Bsub,Tp.Csub});
					}else{
						if (max(club[i].Bsub,club[i].Csub)==club[i].Bsub)
							B.push({club[i].Asub,club[i].Bsub,club[i].Csub});
						else
							C.push({club[i].Asub,club[i].Bsub,club[i].Csub});
					}
				}else A.push({club[i].Asub,club[i].Bsub,club[i].Csub});
			}
			if (pos==2){
				if (B.size()==n/2){
					Node2 Tp=B.top();
					if (max(Tp.Asub,Tp.Csub)+club[i].Bsub>max(club[i].Asub,club[i].Csub)+Tp.Bsub){
						B.pop();B.push({club[i].Asub,club[i].Bsub,club[i].Csub});
						if ((max(Tp.Asub,Tp.Csub)==Tp.Asub))A.push({Tp.Asub,Tp.Bsub,Tp.Csub});
						else C.push({Tp.Asub,Tp.Bsub,Tp.Csub});
					}else{
						if (max(club[i].Asub,club[i].Csub)==club[i].Asub)
							A.push({club[i].Asub,club[i].Bsub,club[i].Csub});
						else
							C.push({club[i].Asub,club[i].Bsub,club[i].Csub});
					}
				}else B.push({club[i].Asub,club[i].Bsub,club[i].Csub});
			}
			if (pos==3){
				if (C.size()==n/2){
					Node3 Tp=C.top();
					if (max(Tp.Bsub,Tp.Asub)+club[i].Csub>max(club[i].Bsub,club[i].Asub)+Tp.Csub){
						C.pop();C.push({club[i].Asub,club[i].Bsub,club[i].Csub});
						if ((max(Tp.Bsub,Tp.Asub)==Tp.Asub))A.push({Tp.Asub,Tp.Bsub,Tp.Csub});
						else B.push({Tp.Asub,Tp.Bsub,Tp.Csub});
					}else{
						if (max(club[i].Bsub,club[i].Asub)==club[i].Bsub)
							B.push({club[i].Asub,club[i].Bsub,club[i].Csub});
						else
							A.push({club[i].Asub,club[i].Bsub,club[i].Csub});
					}
				}else C.push({club[i].Asub,club[i].Bsub,club[i].Csub});
			}
		}
		int ans=0;
		while (!A.empty())ans+=A.top().Asub,A.pop();
		while (!B.empty())ans+=B.top().Bsub,B.pop();
		while (!C.empty())ans+=C.top().Csub,C.pop();
		printf("%d\n",ans);
	} 
	return 0;
} 
