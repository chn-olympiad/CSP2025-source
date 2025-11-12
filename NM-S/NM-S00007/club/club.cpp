#include <bits/stdc++.h>
using namespace std;
int t;
struct Node
{
    int id;
    int part;
    int feeling;
    bool visited = false;
} all[100005], part[3][50002];
bool cmp(Node x, Node y){
    return x.feeling > y.feeling;
}/*
int s(int i, int n, int a1, int a2, int a3, int ans1, int ans2, int ans3, auto part1, auto part2, auto part3){
    if (part1.size() == n / 2 || part1.find(all[i].id) != part1.end()){
        int s = ans1 + ans2 + ans3;
        return s;
    }
    if (part2.size() == n / 2 || part2.find(all[i].id) != part2.end()){
        int s = ans1 + ans2 + ans3;
        return s;
    }
    if (part3.size() == n / 2 || part3.find(all[i].id) != part3.end()){
        int s = ans1 + ans2 + ans3;
        return s;
    }
    if (all[i].part == 1){
        part1.insert(all[i].id);
        ans1 += all[i].feeling;
        for (int j = 1;j <= 3 * n;j++){
            if (all[j].id == all[i].id)all[j].visited = true;
        }
        a1 = max(a1, s(i++, n, a1, a2, a3, ans1, ans2, ans3, part1, part2, part3));
        for (int j = 1;j <= 3 * n;j++){
            if (all[j].id == all[i].id)all[j].visited = false;
        }
        part1.erase(part1.find(all[i].id));
        ans1 -= all[i].feeling;
    }
    if (all[i].part == 2){
        part2.insert(all[i].id);
        ans2 += all[i].feeling;
        for (int j = 1;j <= 3 * n;j++){
            if (all[j].id == all[i].id)all[j].visited = true;
        }
        a2 = max(a2, s(i++, n, a1, a2, a3, ans1, ans2, ans3, part1, part2, part3));
        for (int j = 1;j <= 3 * n;j++){
            if (all[j].id == all[i].id)all[j].visited = false;
        }
        part2.erase(part2.find(all[i].id));
        ans2 -= all[i].feeling;
    }
    if (all[i].part == 3){
        part3.insert(all[i].id);
        ans3 += all[i].feeling;
        for (int j = 1;j <= 3 * n;j++){
            if (all[j].id == all[i].id)all[j].visited = true;
        }
        a3 = max(a3, s(i++, n, a1, a2, a3, ans1, ans2, ans3, part1, part2, part3));
//                     s(i++, n, )
        for (int j = 1;j <= 3 * n;j++){
            if (all[j].id == all[i].id)all[j].visited = false;
        }
        part3.erase(part3.find(all[i].id));
        ans3 -= all[i].feeling;
    }
    return max(a1, max(a2, a3));
}*/
int main(){
    //freopen("club.in", "r", stdin);
    //freopen("club.out", "w", stdout);
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        memset(all, 0, sizeof(all));
        int ans1 = 0, pos = 0;//, ans = 0, ans1 = 0, ans1 = 0, ans2 = 0, ans3 = 0, a1 = 0, a2 = 0, a3 = 0;
        set<int> part1, part2, part3;
//        Node part1[50002], part2[5002], part3[5002];
        for (int id = 1;id <= n;id++){
            for (int part = 1;part <= 3;part++){
                int s;
                cin >> s;
                pos++;
                all[pos].id = id;
                all[pos].part = part;
                all[pos].feeling = s;
                //cout << all[pos].id << " " << all[pos].part << " " << all[pos].feeling << "\n";
            }
        }
        //cout << s(1, n, 0, 0, 0, 0, 0, 0, *part1, *part2, *part3);
        sort(all + 1, all + n * 3 + 1, cmp);
        /*
		当我们完成了sort，接下来该干啥？
		使用贪心！
		但是有个问题
		就是如果某最大值的all[i].feeling想要加入其所在的all[i].part但是该part人数满了，我们该怎么办？
		首先，找到相同id的其余两个all[i]
		并在其中选择最大的all[i].feeling
		如果那个也满了，则选择最小的那个part
		否则直接加入所在part即可
        */
        for (int i = 1;i <= 3 * n;i++){
            if (all[i].part == 1 && all[i].visited == false && part1.find(all[i].id) == part1.end()){
                if (part1.size() == n / 2){
                    bool activited = false;
                	for (int j = 1;j <= 3 * n;i++){
                		if (all[j].id == all[i].id && all[j].part == 2 && part2.size() < n / 2 && part2.find(all[i].id) == part2.end()){
                			part2.insert(all[j].id);
                			ans1 += all[j].feeling;
                			all[j].visited = true;
                			activited = true;
                			break;
						}
						if (all[j].id == all[i].id && all[j].part == 3 && part3.size() < n / 2 && part3.find(all[i].id) == part3.end()){
                            part3.insert(all[j].id);
                            all[j].visited = true;
                            ans1 += all[j].feeling;
                            activited = true;
                            break;
						}
					}
				}
				else{
                    part1.insert(all[i].id);
                    for (int j = i;j <= 3 * n;j++){
                        if (all[j].id = all[i].id)all[j].visited = true;
                    }
                    ans1 += all[i].feeling;
				}
            }
            else if (all[i].part == 2 && all[i].visited == false && part2.find(all[i].id) == part2.end()){
                if (part2.size() == n / 2){
                    bool activited = false;
                    for (int j = 1;j <= 3 * n;j++){
                        if (all[j].id == all[i].id && all[j].part == 1 && part1.size() < n / 2 && part1.find(all[i].id) == part1.end()){
                            part1.insert(all[j].id);
                            ans1+=all[j].feeling;
                            all[j].visited = true;
                            activited = true;
                            break;
                        }
                        if (all[j].id == all[i].id && activited == true)all[j].visited = true;
                        if (all[j].id == all[i].id && all[j].part == 3 && part3.size() < n / 2 && part3.find(all[i].id) == part3.end()){
                            part3.insert(all[j].id);
                            ans1+=all[j].feeling;
                            all[j].visited = true;
                            activited = true;
                            break;
                        }
                        if (all[j].id == all[i].id && activited == true)all[j].visited = true;
                    }
                }
                else
                {
                    part2.insert(all[i].id);
                    for (int j = i;j <= 3 * n;j++){
                        if (all[j].id = all[i].id)all[j].visited = true;
                    }
                    ans1 += all[i].feeling;
                }
            }
            else if (all[i].part == 3 && all[i].visited == false && part3.find(all[i].id) == part3.end()){
                if (part3.size() == n / 2){
                    bool activited = false;
                    for (int j = 1;j <= 3 * n;j++){
                        if (all[j].id == all[i].id && all[j].part == 1 && part1.size() < n / 2 && part1.find(all[i].id) == part1.end()){
                            part1.insert(all[j].id);
                            ans1+=all[j].feeling;
                            all[j].visited = true;
                            activited = true;
                            break;
                        }
                        if (all[j].id == all[i].id && activited == true)all[j].visited = true;
                        if (all[j].id == all[i].id && all[j].part == 2 && part2.size() < n / 2 && part2.find(all[i].id) == part2.end()){
                			part2.insert(all[j].id);
                			ans1 += all[j].feeling;
                			all[j].visited = true;
                			activited = true;
                			break;
						}
						if (all[j].id == all[i].id && activited == true)all[j].visited = true;
                    }
                }
                else{
                    part3.insert(all[i].id);
                    for (int j = i;j <= 3 * n;j++){
                        if (all[j].id = all[i].id)all[j].visited = true;
                    }
                    ans1 += all[i].feeling;
                }
            }
        }
        cout << ans1 << "\n";
    }
}
