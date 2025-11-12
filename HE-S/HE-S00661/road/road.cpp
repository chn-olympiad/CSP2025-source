#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	srand(time(NULL));
	cout<<(rand()/100*100+rand()/46*126+rand()*142/7+66*rand()-rand()/rand())%100000;
	fclose(stdin);fclose(stdout);
	return 0;
}
// CCF,please let me AK CSP-J.Thank you!
/* |00000000 00|||||00 |0000000| |||||||||
   |00000000 0|00000|0 |0000000| |00000000
   |00000000 |0000000| 0|00000|0 |00000000
   |00000000 |0000000| 0|00000|0 |||||||||
   |00000000 |0000000| 00|000|00 |00000000
   |00000000 0|00000|0 000|0|000 |00000000
   ||||||||| 00|||||00 0000|0000 |||||||||
*/
