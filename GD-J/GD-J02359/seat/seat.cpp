#include<bits/stdc++.h>
using namespace std;
//Okay, ich muss verstehe N und M samt kleiner als 10
//Also es gibt kinde des "short"
const int WYNN_MAXN_SIZE=105;
short Graph_seats[WYNN_MAXN_SIZE][WYNN_MAXN_SIZE];
short Student_Grades[WYNN_MAXN_SIZE];
bool cmp(short Left_Number,short Right_Number){		//Laess die Numbers sein von gross zu klein
	return Left_Number>Right_Number?true:false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	int n,m;
	cin>>n>>m;
	for(short i=1;i<=n*m;i++)cin>>Student_Grades[i];
	short Personal_Grade=Student_Grades[1];
	sort(Student_Grades+1,Student_Grades+n*m+1,cmp);	//Mach diese Numbers in Ordnung(mit Function cmp).,
	if(Student_Grades[1]==Personal_Grade){	//Special situations(Das werdt retten viel Zeit wenn ich kann weissen es)
		cout<<1<<' '<<1<<'\n';
		return 0;
	}else if(Student_Grades[n*m]==Personal_Grade){
		cout<<n<<' '<<m<<'\n';
		return 0;
	}
	bool Direction=false;
	int Follow_top=1;
	for(short i=1;i<=n;i++){
		if(!Direction)
			for(short j=1;j<=m;j++)
				Graph_seats[i][j]=Student_Grades[Follow_top++];
		else
			for(short j=m;j>=1;j--)
				Graph_seats[i][j]=Student_Grades[Follow_top++];
		Direction=!Direction;
	}
	for(short i=1;i<=n;i++){
		if(Graph_seats[i][1]>=Graph_seats[i][m]){
			if( !(Graph_seats[i][m]<=Personal_Grade && Personal_Grade<=Graph_seats[i][1]))continue;
			for(short j=m;j>=1;j--)
				if(Personal_Grade==Graph_seats[i][j]){
					cout<<i<<' '<<j<<'\n';
					return 0;
				}
		}
		else{
			if( !(Graph_seats[i][1]<=Personal_Grade && Personal_Grade<=Graph_seats[i][m]))continue;
			int Left_Array=1,Right_Array=m;
			while(Left_Array<=Right_Array){		//Find die Position mit kleine Zeit
				int cache_mid=(Left_Array+Right_Array)/2;
				if(Graph_seats[i][cache_mid]==Personal_Grade){
					cout<<i<<' '<<cache_mid<<'\n';
					return 0;
				}
				if(Graph_seats[i][cache_mid]<Personal_Grade)Left_Array=cache_mid+1;
				else Right_Array=cache_mid-1;
			}
		}
	}
	return 0;
}
