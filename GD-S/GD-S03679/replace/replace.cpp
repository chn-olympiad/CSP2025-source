//16:30 好累好累鸭
#include<bits/stdc++.h>
using namespace std;
//六个蛋挞19.9,两份土豆泥9.9,40块鸡块39.9,15块热辣脆骨鸡19.9
//我要当[仓储费]的保温杯 
/*
 ____________                     ____________                     _     _         __              _      _________      
|           |     |▔▔▔▔▔|   |           |        |\          ┊┊  | |       ┊ \            | ┊   ┊ _______┊    
▔▔┊┊▔▔      | |▔▔  | |   ▔▔┊┊▔▔        ||\\         ┊┊ | |        ┊┊\\         |  ┊   ┊┊                                    
    ┊┊          | |      | |       ┊┊           ||  \\        ┊┊| |         ┊┊\\        ||┊┊   ┊┊______                  
    ┊┊          | |      | |       ┊┊          ||____\\       ┊ _ ┊         ┊┊ \\      || ┊┊   ┊ _______┊                   
    ┊┊          | |      | |       ┊┊         |________\      ┊┊\ \         ┊┊  \\    ||  ┊┊   ┊┊
    ┊┊          |  |_____| |       ┊┊        ||        \\     ┊┊ \ \        ┊┊   \\  ||   ┊┊   ┊┊                  
 ___┊┊_____     |          |    ___┊┊_____  ||          \\    ┊┊  \ \       ┊┊    \\||    ┊┊   ┊┊______         
|           |     ▔▔▔▔▔▔   |           | ||            \\   ┊┊   \_\      ┊┊     \|     ┊┊   ┊________┊                    
▔▔▔▔▔▔                     ▔▔▔▔▔▔                     ▔
my blog:hjbhawa.github.io/hjbh.github.io
*/
int n,q;
string s[3][2*114514],s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[1][i]>>s[2][i];
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		cout<<(s1.size()+s2.size())/2;
	}
}
//ahhhhhhhhhhh baby you are a pt,tw,nj,fdfzyxj,hxrwbgm,hxchshbx
//求解密 
