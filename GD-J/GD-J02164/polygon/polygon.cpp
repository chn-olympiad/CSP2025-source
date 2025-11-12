#include<cstdio>
#include<algorithm>
int main(){
	freopen("polygon.in","r",stdin);
	freopen("poylgon.out","w",stdout);
	int x,y[5005],max=-1,can=0;
	scanf("%d",&x);
	for(int a(1);a<=x;++a){
		scanf("%d",&y[a]);
		max=std::max(max,y[a]);
	}
	for(int the_one(3);the_one<=x;++the_one){
		for(int the_two(2);the_two<the_one;++the_two){
			for(int the_three(1);the_three<the_two;++the_three){
				if(y[the_one]+y[the_two]+y[the_three]>max*2){
//					printf("%d %d %d\n",y[the_one],y[the_two],y[the_three]);
					can++;
				}
			}
		}
	}
	printf("%d",can);
	return 0;
}
/*
       _________
      / _____  /\
     / /    / / /
    / /____/ / /
   / __  ___/ /
  / /\ \ \__\/
 / / /\ \ \
/_/ /  \ \_\
|_|/    \|_|
       _________
      / _____  /\
     / /    / / /
    / /____/ / /
   / _______/ /
  / /\______\/
 / / /
/_/ /
|_|/
*/
